/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <gmock/gmock.h>

#include "FrameTimeline.h"
#include "Scheduler/EventThread.h"
#include "Scheduler/MessageQueue.h"

namespace android::mock {

class MessageQueue : public android::MessageQueue {
public:
    MessageQueue();
    ~MessageQueue() override;

    MOCK_METHOD1(init, void(const sp<SurfaceFlinger>&));
    MOCK_METHOD1(setInjector, void(sp<EventThreadConnection>));
    MOCK_METHOD0(waitMessage, void());
    MOCK_METHOD1(postMessage, void(sp<MessageHandler>&&));
    MOCK_METHOD0(invalidate, void());
    MOCK_METHOD0(refresh, void());
    MOCK_METHOD3(initVsync,
                 void(scheduler::VSyncDispatch&, frametimeline::TokenManager&,
                      std::chrono::nanoseconds));
    MOCK_METHOD1(setDuration, void(std::chrono::nanoseconds workDuration));
    MOCK_METHOD0(nextExpectedInvalidate, std::optional<std::chrono::steady_clock::time_point>());
};

} // namespace android::mock
