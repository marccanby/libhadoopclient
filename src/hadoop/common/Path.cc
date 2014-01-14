/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Path.h"

namespace hadoop {
namespace common {

bool Path::IsAbsolute(const string & path) {
  if (path.length()>0 && path[0]=='/') {
    return true;
  }
  return false;
}

string Path::GetParent(const string & path) {
  size_t lastSlash = path.rfind('/');
  if (lastSlash == path.npos) {
    return ".";
  }
  if (lastSlash == 0) {
    return "/";
  }
  return path.substr(0, lastSlash);
}

string Path::GetName(const string & path) {
  size_t lastSlash = path.rfind('/');
  if (lastSlash == path.npos) {
    return path;
  }
  return path.substr(lastSlash+1);
}


bool Path::Valid(const string& path) {
  for (char c : path) {
    if (c=='#' || c==':' || c=='?') {
      return false;
    }
  }
  return true;
}

string Path::JoinPath(const string & parent, const string & name) {
  if (parent.empty()) {
    return name;
  }
  if (name.empty()) {
    return parent;
  }
  if (parent[parent.length()-1] == '/') {
    return parent + name;
  } else {
    return parent + "/" + name;
  }
}

}
}

