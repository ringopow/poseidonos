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

#ifdef _ADMIN_ENABLED
#pragma once

#include "spdk/pos.h"
#include "spdk/nvme_spec.h"
#include "src/admin/component_manager.h"
#include "src/admin/smart_log_mgr.h"
#include "src/event_scheduler/callback.h"
#include "src/io/general_io/io_submit_handler.h"
namespace pos
{
// disk and cpu
static const int NO_OF_COMPONENTS = 2;
static const uint64_t NVME_SPEC_BYTE_UNIT = 512 * 1000;
static const int NO_OF_TEMP_SENSORS = 8;
static const int KELVIN_TO_CELSIUS = 273;
class DiskSmartCompleteHandler : public Callback
{
public:
    DiskSmartCompleteHandler(struct spdk_nvme_health_information_page* resultPage, uint32_t volId, uint32_t origincore, pos_io* io, CallbackSmartPtr callback);
    ~DiskSmartCompleteHandler(void) override;

private:
    bool _DoSpecificJob(void) override;
    void _AddComponentTemperature(void);
    void _SetValfromSmartLogMgr(void);
    struct spdk_nvme_health_information_page* resultPage;
    uint32_t volId;
    uint32_t originCore;
    pos_io* io;
    CallbackSmartPtr callback;
};
} // namespace pos
#endif
