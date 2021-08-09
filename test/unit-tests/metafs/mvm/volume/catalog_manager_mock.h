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

#include <gmock/gmock.h>

#include <list>
#include <string>
#include <vector>

#include "src/metafs/mvm/volume/catalog_manager.h"

namespace pos
{
class MockCatalogManager : public CatalogManager
{
public:
    using CatalogManager::CatalogManager;
    MOCK_METHOD(void, Init, (MetaVolumeType volumeType, MetaLpnType regionBaseLpn, MetaLpnType maxVolumeLpn), (override));
    MOCK_METHOD(MetaLpnType, GetRegionSizeInLpn, (), (override));
    MOCK_METHOD(void, Bringup, (), (override));
    MOCK_METHOD(void, SetMss, (MetaStorageSubsystem* mss), (override));
    MOCK_METHOD(bool, SaveContent, (), (override));
    MOCK_METHOD(void, Finalize, (), (override));
    MOCK_METHOD(bool, LoadVolCatalog, ());
    MOCK_METHOD(bool, CheckVolumeValidity, ());
    MOCK_METHOD(bool, BackupContent, (MetaVolumeType tgtVol, MetaLpnType baseLpn, MetaLpnType lpnCnts));
    MOCK_METHOD(bool, RestoreContent, (MetaVolumeType tgtVol, MetaLpnType baseLpn, MetaLpnType lpnCnts));
    MOCK_METHOD(bool, CreateCatalog, (MetaLpnType maxVolumeLpn, uint32_t maxFileSupportNum, bool save));
    MOCK_METHOD(void, RegisterRegionInfo, (MetaRegionType regionType, MetaLpnType baseLpn, MetaLpnType maxLpn));
};

} // namespace pos
