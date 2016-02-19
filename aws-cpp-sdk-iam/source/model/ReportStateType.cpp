/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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
#include <aws/iam/model/ReportStateType.h>
#include <aws/core/utils/HashingUtils.h>

using namespace Aws::Utils;

static const int STARTED_HASH = HashingUtils::HashString("STARTED");
static const int INPROGRESS_HASH = HashingUtils::HashString("INPROGRESS");
static const int COMPLETE_HASH = HashingUtils::HashString("COMPLETE");

namespace Aws
{
namespace IAM
{
namespace Model
{
namespace ReportStateTypeMapper
{
ReportStateType GetReportStateTypeForName(const Aws::String& name)
{
  int hashCode = HashingUtils::HashString(name.c_str());

  if (hashCode == STARTED_HASH)
  {
    return ReportStateType::STARTED;
  }
  else if (hashCode == INPROGRESS_HASH)
  {
    return ReportStateType::INPROGRESS;
  }
  else if (hashCode == COMPLETE_HASH)
  {
    return ReportStateType::COMPLETE;
  }

  return ReportStateType::NOT_SET;
}

Aws::String GetNameForReportStateType(ReportStateType value)
{
  switch(value)
  {
  case ReportStateType::STARTED:
    return "STARTED";
  case ReportStateType::INPROGRESS:
    return "INPROGRESS";
  case ReportStateType::COMPLETE:
    return "COMPLETE";
  default:
    return "";
  }
}

} // namespace ReportStateTypeMapper
} // namespace Model
} // namespace IAM
} // namespace Aws