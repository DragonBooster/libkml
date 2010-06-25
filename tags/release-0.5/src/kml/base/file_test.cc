// Copyright 2008, Google Inc. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
//
//  1. Redistributions of source code must retain the above copyright notice, 
//     this list of conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//  3. Neither the name of Google Inc. nor the names of its contributors may be
//     used to endorse or promote products derived from this software without
//     specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
// EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "kml/base/file.h"
#include "gtest/gtest.h"

#ifndef DATADIR
#error DATADIR must be defined!
#else
static const std::string kDataDir = DATADIR;
#endif

namespace kmlbase {

class FileTest : public testing::Test {
};

TEST_F(FileTest, TestReadFileToString) {
  const std::string kDoc = kDataDir + "/kmz/doc.kmz";
  std::string file_data;
  ASSERT_TRUE(File::ReadFileToString(kDoc, &file_data));
  ASSERT_FALSE(file_data.empty());
  // doc.kmz is 180 bytes.
  ASSERT_EQ(static_cast<size_t>(180), file_data.size());
}

TEST_F(FileTest, TestWriteStringToFile) {
  // Create a temp file into which we'll write data.
  std::string tempfile;
  ASSERT_TRUE(File::CreateNewTempFile(&tempfile));
  ASSERT_FALSE(tempfile.empty());
  // Write some data.
  const std::string kText = "tom dick harry";
  ASSERT_TRUE(File::WriteStringToFile(kText, tempfile));
  // Read the file back into a different string and assert equality.
  std::string file_data;
  ASSERT_TRUE(File::ReadFileToString(tempfile, &file_data));
  ASSERT_FALSE(file_data.empty());
  ASSERT_EQ(kText, file_data);
  // Remove the temp file.
  ASSERT_TRUE(File::Delete(tempfile));
}

TEST_F(FileTest, TestExists) {
  const std::string kDoc = kDataDir + "/kmz/doc.kmz";
  const std::string kNoSuchFile = kDataDir + "/kmz/nosuchfile";
  ASSERT_TRUE(File::Exists(kDoc));
  ASSERT_FALSE(File::Exists(kNoSuchFile));
}

TEST_F(FileTest, TestDelete) {
  // Create a temp file.
  std::string tempfile;
  ASSERT_TRUE(File::CreateNewTempFile(&tempfile));
  // Assert it was created.
  ASSERT_FALSE(tempfile.empty());
  ASSERT_TRUE(File::Exists(tempfile));
  // Delete and confirm removal.
  ASSERT_TRUE(File::Delete(tempfile));
  ASSERT_FALSE(File::Exists(tempfile));
}

TEST_F(FileTest, TestCreateNewTempFile) {
  ASSERT_TRUE(false == File::CreateNewTempFile(NULL));
  std::string temp_filename;
  ASSERT_TRUE(File::CreateNewTempFile(&temp_filename));
  ASSERT_FALSE(temp_filename.empty());
  ASSERT_TRUE(File::Delete(temp_filename));
}

TEST_F(FileTest, TestJoinPaths) {
  // TODO: win32 separators for cross-platform testing.
  const std::string kPath1NoSep("/tom/dick");
  const std::string kPath1Sep("/tom/dick/");
  const std::string kPath2("harry");
  const std::string kExpected("/tom/dick/harry");
  // Passing cases.
  ASSERT_EQ(kExpected, File::JoinPaths(kPath1NoSep, kPath2));
  ASSERT_EQ(kExpected, File::JoinPaths(kPath1Sep, kPath2));
  // Pathological cases.
  // Joining with an empty string does not modify anything.
  ASSERT_EQ(kPath1NoSep, File::JoinPaths(kPath1NoSep, ""));
  ASSERT_EQ(kPath2, File::JoinPaths("", kPath2));
  ASSERT_EQ(std::string(""), File::JoinPaths("", ""));
}

}  // end namespace kmlbase

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}