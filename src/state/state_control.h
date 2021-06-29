/*
 *   BSD LICENSE
 *   Copyright (c) 2021 Samsung Electronics Corporation
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Intel Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <future>
#include <string>

#include "src/state/interface/i_state_control.h"

using namespace std;

namespace pos
{
class StatePublisher;
class StateList;

class StateControl : public IStateControl
{
public:
    StateControl(void);
    StateControl(StateContext* defaultCtx);
    virtual ~StateControl(void);
    void Subscribe(IStateObserver* sub, string name) override;
    void Unsubscribe(IStateObserver* sub) override;
    StateContext* GetState(void) override;
    void Invoke(StateContext* ctx) override;
    void Remove(StateContext* ctx) override;
    bool Exists(SituationEnum situ) override;

private:
    bool _Exists(StateContext* ctx);
    bool _Exists(StateEnum state);
    void _ListUpdated(StateContext* front);
    void _UpdateState(void);
    void _ChangeState(StateContext* next);
    void _NotifyState(StateContext* prev, StateContext* next);

    StatePublisher* publisher = nullptr;
    StateContext* curr = nullptr;
    StateList* stateList = nullptr;
    future<void> async_future;
    StateContext defaultCtx{"StateManager", SituationEnum::DEFAULT};
};
} // namespace pos
