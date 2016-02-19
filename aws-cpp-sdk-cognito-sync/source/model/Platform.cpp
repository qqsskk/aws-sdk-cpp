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
#include <aws/cognito-sync/model/Platform.h>
#include <aws/core/utils/HashingUtils.h>

using namespace Aws::Utils;

static const int APNS_HASH = HashingUtils::HashString("APNS");
static const int APNS_SANDBOX_HASH = HashingUtils::HashString("APNS_SANDBOX");
static const int GCM_HASH = HashingUtils::HashString("GCM");
static const int ADM_HASH = HashingUtils::HashString("ADM");

namespace Aws
{
namespace CognitoSync
{
namespace Model
{
namespace PlatformMapper
{
Platform GetPlatformForName(const Aws::String& name)
{
  int hashCode = HashingUtils::HashString(name.c_str());

  if (hashCode == APNS_HASH)
  {
    return Platform::APNS;
  }
  else if (hashCode == APNS_SANDBOX_HASH)
  {
    return Platform::APNS_SANDBOX;
  }
  else if (hashCode == GCM_HASH)
  {
    return Platform::GCM;
  }
  else if (hashCode == ADM_HASH)
  {
    return Platform::ADM;
  }

  return Platform::NOT_SET;
}

Aws::String GetNameForPlatform(Platform value)
{
  switch(value)
  {
  case Platform::APNS:
    return "APNS";
  case Platform::APNS_SANDBOX:
    return "APNS_SANDBOX";
  case Platform::GCM:
    return "GCM";
  case Platform::ADM:
    return "ADM";
  default:
    return "";
  }
}

} // namespace PlatformMapper
} // namespace Model
} // namespace CognitoSync
} // namespace Aws