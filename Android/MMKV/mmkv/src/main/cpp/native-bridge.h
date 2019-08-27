/*
 * Tencent is pleased to support the open source community by making
 * MMKV available.
 *
 * Copyright (C) 2018 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MMKV_NATIVE_BRIDGE_H
#define MMKV_NATIVE_BRIDGE_H

#include <string>

enum MMKVRecoverStrategic : int {
    OnErrorDiscard = 0,
    OnErrorRecover,
};

namespace mmkv {

MMKVRecoverStrategic onMMKVCRCCheckFail(const std::string &mmapID);

MMKVRecoverStrategic onMMKVFileLengthError(const std::string &mmapID);

void mmkvLog(int level,
             const std::string &file,
             int line,
             const std::string &function,
             const std::string &message);

void onContentChangedByOuterProcess(const std::string &mmapID);
} // namespace mmkv

extern int g_android_api;

#endif //MMKV_NATIVE_BRIDGE_H
