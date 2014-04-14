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

#include "PowerControlSetCachedProperty.h"

using namespace std;

PowerControlSetCachedProperty::PowerControlSetCachedProperty(
    UIntN participantIndex,
    UIntN domainIndex,
    const DomainProperties& domainProperties,
    const PolicyServicesInterfaceContainer& policyServices)
    : CachedProperty(), DomainProperty(participantIndex, domainIndex, domainProperties, policyServices),
    m_powerControlStatusSet(std::vector<PowerControlStatus>())
{
}

PowerControlSetCachedProperty::~PowerControlSetCachedProperty()
{
}

Bool PowerControlSetCachedProperty::implementsPowerControlInterface(void)
{
    return getDomainProperties().implementsPowerControlInterface();
}

const PowerControlStatusSet& PowerControlSetCachedProperty::getControlSet(void)
{
    if (implementsPowerControlInterface())
    {
        if (isCacheValid() == false)
        {
            refresh();
        }
        return m_powerControlStatusSet;
    }
    else
    {
        throw dptf_exception("Domain does not support the power control interface.");
    }
}

Bool PowerControlSetCachedProperty::supportsProperty(void)
{
    if (isCacheValid() == false)
    {
        refresh();
    }
    return implementsPowerControlInterface();
}

void PowerControlSetCachedProperty::refreshData(void)
{
    if (implementsPowerControlInterface())
    {
        m_powerControlStatusSet =
            getPolicyServices().domainPowerControl->getPowerControlStatusSet(
                getParticipantIndex(), getDomainIndex());
    }
}