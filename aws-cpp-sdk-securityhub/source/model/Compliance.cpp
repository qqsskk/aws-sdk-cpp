﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/securityhub/model/Compliance.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace SecurityHub
{
namespace Model
{

Compliance::Compliance() : 
    m_status(ComplianceStatus::NOT_SET),
    m_statusHasBeenSet(false)
{
}

Compliance::Compliance(JsonView jsonValue) : 
    m_status(ComplianceStatus::NOT_SET),
    m_statusHasBeenSet(false)
{
  *this = jsonValue;
}

Compliance& Compliance::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("Status"))
  {
    m_status = ComplianceStatusMapper::GetComplianceStatusForName(jsonValue.GetString("Status"));

    m_statusHasBeenSet = true;
  }

  return *this;
}

JsonValue Compliance::Jsonize() const
{
  JsonValue payload;

  if(m_statusHasBeenSet)
  {
   payload.WithString("Status", ComplianceStatusMapper::GetNameForComplianceStatus(m_status));
  }

  return payload;
}

} // namespace Model
} // namespace SecurityHub
} // namespace Aws
