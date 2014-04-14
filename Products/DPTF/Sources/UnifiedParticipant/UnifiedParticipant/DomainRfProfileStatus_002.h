/******************************************************************************
** Copyright (c) 2014 Intel Corporation All Rights Reserved
**
** Licensed under the Apache License, Version 2.0 (the "License"); you may not
** use this file except in compliance with the License.
**
** You may obtain a copy of the License at
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
** WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**
** See the License for the specific language governing permissions and
** limitations under the License.
**
******************************************************************************/

#pragma once

#include "Dptf.h"
#include "DomainRfProfileStatusInterface.h"
#include "ComponentExtendedInterface.h"
#include "ParticipantServicesInterface.h"

//
// version 002 is for wireless
//

class DomainRfProfileStatus_002 final : public DomainRfProfileStatusInterface,
    public ComponentExtendedInterface
{
public:

    DomainRfProfileStatus_002(ParticipantServicesInterface* participantServicesInterface);
    ~DomainRfProfileStatus_002(void);

    // DomainRfProfileStatusInterface
    virtual RfProfileData getRfProfileData(UIntN participantIndex, UIntN domainIndex) override final;

    // ComponentExtendedInterface
    virtual void clearCachedData(void) override final;
    virtual XmlNode* getXml(UIntN domainIndex) override final;

private:

    // hide the copy constructor and = operator
    DomainRfProfileStatus_002(const DomainRfProfileStatus_002& rhs);
    DomainRfProfileStatus_002& operator=(const DomainRfProfileStatus_002& rhs);

    ParticipantServicesInterface* m_participantServicesInterface;
};