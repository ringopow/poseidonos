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

#include "src/io/general_io/rba_state_manager.h"
#include "src/array_models/interface/i_array_info.h"

namespace pos
{
RBAStateManager::RBAStateManager(std::string arrayName)
: VolumeEvent("RBAStateManager", arrayName)
{
}

RBAStateManager::~RBAStateManager()
{
}

void
RBAStateManager::CreateRBAState(uint32_t volumeID, uint64_t totalRBACount)
{
}

void
RBAStateManager::DeleteRBAState(uint32_t volumeID)
{
}

bool
RBAStateManager::BulkAcquireOwnership(uint32_t volumeID,
    BlkAddr startRba,
    uint32_t count)
{
    return false;
}

void
RBAStateManager::BulkReleaseOwnership(uint32_t volumeID,
    BlkAddr startRba,
    uint32_t count)
{
}

RBAStateManager::RBAState::RBAState(void)
{
}

bool
RBAStateManager::VolumeCreated(std::string volName, int volID, uint64_t volSizeByte,
    uint64_t maxiops, uint64_t maxbw, std::string arrayName)
{
    return true;
}

bool
RBAStateManager::VolumeDeleted(std::string volName, int volID, uint64_t volSizeByte, std::string arrayName)
{
    return true;
}

bool
RBAStateManager::VolumeMounted(std::string volName, std::string subnqn, int volID, uint64_t volSizeByte,
    uint64_t maxiops, uint64_t maxbw, std::string arrayName)
{
    return true;
}

bool
RBAStateManager::VolumeUnmounted(std::string volName, int volID, std::string arrayName)
{
    return true;
}

bool
RBAStateManager::VolumeLoaded(std::string name, int id, uint64_t totalSize,
    uint64_t maxiops, uint64_t maxbw, std::string arrayName)
{
    return true;
}

bool
RBAStateManager::VolumeUpdated(std::string volName, int volID, uint64_t maxiops, uint64_t maxbw, std::string arrayName)
{
    return true;
}

} // namespace pos
