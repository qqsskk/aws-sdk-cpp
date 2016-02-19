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
#pragma once
#include <aws/elasticache/ElastiCache_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSStreamFwd.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/elasticache/model/RecurringCharge.h>

namespace Aws
{
namespace Utils
{
namespace Xml
{
  class XmlNode;
} // namespace Xml
} // namespace Utils
namespace ElastiCache
{
namespace Model
{

  /**
   * <p>Represents the output of a <i>PurchaseReservedCacheNodesOffering</i>
   * action.</p>
   */
  class AWS_ELASTICACHE_API ReservedCacheNode
  {
  public:
    ReservedCacheNode();
    ReservedCacheNode(const Aws::Utils::Xml::XmlNode& xmlNode);
    ReservedCacheNode& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    void OutputToStream(Aws::OStream& ostream, const char* location, unsigned index, const char* locationValue) const;
    void OutputToStream(Aws::OStream& oStream, const char* location) const;

    /**
     * <p>The unique identifier for the reservation.</p>
     */
    inline const Aws::String& GetReservedCacheNodeId() const{ return m_reservedCacheNodeId; }

    /**
     * <p>The unique identifier for the reservation.</p>
     */
    inline void SetReservedCacheNodeId(const Aws::String& value) { m_reservedCacheNodeIdHasBeenSet = true; m_reservedCacheNodeId = value; }

    /**
     * <p>The unique identifier for the reservation.</p>
     */
    inline void SetReservedCacheNodeId(Aws::String&& value) { m_reservedCacheNodeIdHasBeenSet = true; m_reservedCacheNodeId = value; }

    /**
     * <p>The unique identifier for the reservation.</p>
     */
    inline void SetReservedCacheNodeId(const char* value) { m_reservedCacheNodeIdHasBeenSet = true; m_reservedCacheNodeId.assign(value); }

    /**
     * <p>The unique identifier for the reservation.</p>
     */
    inline ReservedCacheNode& WithReservedCacheNodeId(const Aws::String& value) { SetReservedCacheNodeId(value); return *this;}

    /**
     * <p>The unique identifier for the reservation.</p>
     */
    inline ReservedCacheNode& WithReservedCacheNodeId(Aws::String&& value) { SetReservedCacheNodeId(value); return *this;}

    /**
     * <p>The unique identifier for the reservation.</p>
     */
    inline ReservedCacheNode& WithReservedCacheNodeId(const char* value) { SetReservedCacheNodeId(value); return *this;}

    /**
     * <p>The offering identifier.</p>
     */
    inline const Aws::String& GetReservedCacheNodesOfferingId() const{ return m_reservedCacheNodesOfferingId; }

    /**
     * <p>The offering identifier.</p>
     */
    inline void SetReservedCacheNodesOfferingId(const Aws::String& value) { m_reservedCacheNodesOfferingIdHasBeenSet = true; m_reservedCacheNodesOfferingId = value; }

    /**
     * <p>The offering identifier.</p>
     */
    inline void SetReservedCacheNodesOfferingId(Aws::String&& value) { m_reservedCacheNodesOfferingIdHasBeenSet = true; m_reservedCacheNodesOfferingId = value; }

    /**
     * <p>The offering identifier.</p>
     */
    inline void SetReservedCacheNodesOfferingId(const char* value) { m_reservedCacheNodesOfferingIdHasBeenSet = true; m_reservedCacheNodesOfferingId.assign(value); }

    /**
     * <p>The offering identifier.</p>
     */
    inline ReservedCacheNode& WithReservedCacheNodesOfferingId(const Aws::String& value) { SetReservedCacheNodesOfferingId(value); return *this;}

    /**
     * <p>The offering identifier.</p>
     */
    inline ReservedCacheNode& WithReservedCacheNodesOfferingId(Aws::String&& value) { SetReservedCacheNodesOfferingId(value); return *this;}

    /**
     * <p>The offering identifier.</p>
     */
    inline ReservedCacheNode& WithReservedCacheNodesOfferingId(const char* value) { SetReservedCacheNodesOfferingId(value); return *this;}

    /**
     * <p>The cache node type for the reserved cache nodes.</p> <p>Valid node types are
     * as follows:</p> <ul> <li>General purpose: <ul> <li>Current generation:
     * <code>cache.t2.micro</code>, <code>cache.t2.small</code>,
     * <code>cache.t2.medium</code>, <code>cache.m3.medium</code>,
     * <code>cache.m3.large</code>, <code>cache.m3.xlarge</code>,
     * <code>cache.m3.2xlarge</code></li> <li>Previous generation:
     * <code>cache.t1.micro</code>, <code>cache.m1.small</code>,
     * <code>cache.m1.medium</code>, <code>cache.m1.large</code>,
     * <code>cache.m1.xlarge</code></li> </ul></li> <li>Compute optimized:
     * <code>cache.c1.xlarge</code></li> <li>Memory optimized <ul> <li>Current
     * generation: <code>cache.r3.large</code>, <code>cache.r3.xlarge</code>,
     * <code>cache.r3.2xlarge</code>, <code>cache.r3.4xlarge</code>,
     * <code>cache.r3.8xlarge</code></li> <li>Previous generation:
     * <code>cache.m2.xlarge</code>, <code>cache.m2.2xlarge</code>,
     * <code>cache.m2.4xlarge</code></li> </ul></li> </ul> <p><b>Notes:</b></p> <ul>
     * <li>All t2 instances are created in an Amazon Virtual Private Cloud (VPC).</li>
     * <li>Redis backup/restore is not supported for t2 instances.</li> <li>Redis
     * Append-only files (AOF) functionality is not supported for t1 or t2
     * instances.</li> </ul> <p>For a complete listing of cache node types and
     * specifications, see <a href="http://aws.amazon.com/elasticache/details">Amazon
     * ElastiCache Product Features and Details</a> and <a
     * href="http://docs.aws.amazon.com/AmazonElastiCache/latest/UserGuide/CacheParameterGroups.Memcached.html#CacheParameterGroups.Memcached.NodeSpecific">Cache
     * Node Type-Specific Parameters for Memcached</a> or <a
     * href="http://docs.aws.amazon.com/AmazonElastiCache/latest/UserGuide/CacheParameterGroups.Redis.html#CacheParameterGroups.Redis.NodeSpecific">Cache
     * Node Type-Specific Parameters for Redis</a>. </p>
     */
    inline const Aws::String& GetCacheNodeType() const{ return m_cacheNodeType; }

    /**
     * <p>The cache node type for the reserved cache nodes.</p> <p>Valid node types are
     * as follows:</p> <ul> <li>General purpose: <ul> <li>Current generation:
     * <code>cache.t2.micro</code>, <code>cache.t2.small</code>,
     * <code>cache.t2.medium</code>, <code>cache.m3.medium</code>,
     * <code>cache.m3.large</code>, <code>cache.m3.xlarge</code>,
     * <code>cache.m3.2xlarge</code></li> <li>Previous generation:
     * <code>cache.t1.micro</code>, <code>cache.m1.small</code>,
     * <code>cache.m1.medium</code>, <code>cache.m1.large</code>,
     * <code>cache.m1.xlarge</code></li> </ul></li> <li>Compute optimized:
     * <code>cache.c1.xlarge</code></li> <li>Memory optimized <ul> <li>Current
     * generation: <code>cache.r3.large</code>, <code>cache.r3.xlarge</code>,
     * <code>cache.r3.2xlarge</code>, <code>cache.r3.4xlarge</code>,
     * <code>cache.r3.8xlarge</code></li> <li>Previous generation:
     * <code>cache.m2.xlarge</code>, <code>cache.m2.2xlarge</code>,
     * <code>cache.m2.4xlarge</code></li> </ul></li> </ul> <p><b>Notes:</b></p> <ul>
     * <li>All t2 instances are created in an Amazon Virtual Private Cloud (VPC).</li>
     * <li>Redis backup/restore is not supported for t2 instances.</li> <li>Redis
     * Append-only files (AOF) functionality is not supported for t1 or t2
     * instances.</li> </ul> <p>For a complete listing of cache node types and
     * specifications, see <a href="http://aws.amazon.com/elasticache/details">Amazon
     * ElastiCache Product Features and Details</a> and <a
     * href="http://docs.aws.amazon.com/AmazonElastiCache/latest/UserGuide/CacheParameterGroups.Memcached.html#CacheParameterGroups.Memcached.NodeSpecific">Cache
     * Node Type-Specific Parameters for Memcached</a> or <a
     * href="http://docs.aws.amazon.com/AmazonElastiCache/latest/UserGuide/CacheParameterGroups.Redis.html#CacheParameterGroups.Redis.NodeSpecific">Cache
     * Node Type-Specific Parameters for Redis</a>. </p>
     */
    inline void SetCacheNodeType(const Aws::String& value) { m_cacheNodeTypeHasBeenSet = true; m_cacheNodeType = value; }

    /**
     * <p>The cache node type for the reserved cache nodes.</p> <p>Valid node types are
     * as follows:</p> <ul> <li>General purpose: <ul> <li>Current generation:
     * <code>cache.t2.micro</code>, <code>cache.t2.small</code>,
     * <code>cache.t2.medium</code>, <code>cache.m3.medium</code>,
     * <code>cache.m3.large</code>, <code>cache.m3.xlarge</code>,
     * <code>cache.m3.2xlarge</code></li> <li>Previous generation:
     * <code>cache.t1.micro</code>, <code>cache.m1.small</code>,
     * <code>cache.m1.medium</code>, <code>cache.m1.large</code>,
     * <code>cache.m1.xlarge</code></li> </ul></li> <li>Compute optimized:
     * <code>cache.c1.xlarge</code></li> <li>Memory optimized <ul> <li>Current
     * generation: <code>cache.r3.large</code>, <code>cache.r3.xlarge</code>,
     * <code>cache.r3.2xlarge</code>, <code>cache.r3.4xlarge</code>,
     * <code>cache.r3.8xlarge</code></li> <li>Previous generation:
     * <code>cache.m2.xlarge</code>, <code>cache.m2.2xlarge</code>,
     * <code>cache.m2.4xlarge</code></li> </ul></li> </ul> <p><b>Notes:</b></p> <ul>
     * <li>All t2 instances are created in an Amazon Virtual Private Cloud (VPC).</li>
     * <li>Redis backup/restore is not supported for t2 instances.</li> <li>Redis
     * Append-only files (AOF) functionality is not supported for t1 or t2
     * instances.</li> </ul> <p>For a complete listing of cache node types and
     * specifications, see <a href="http://aws.amazon.com/elasticache/details">Amazon
     * ElastiCache Product Features and Details</a> and <a
     * href="http://docs.aws.amazon.com/AmazonElastiCache/latest/UserGuide/CacheParameterGroups.Memcached.html#CacheParameterGroups.Memcached.NodeSpecific">Cache
     * Node Type-Specific Parameters for Memcached</a> or <a
     * href="http://docs.aws.amazon.com/AmazonElastiCache/latest/UserGuide/CacheParameterGroups.Redis.html#CacheParameterGroups.Redis.NodeSpecific">Cache
     * Node Type-Specific Parameters for Redis</a>. </p>
     */
    inline void SetCacheNodeType(Aws::String&& value) { m_cacheNodeTypeHasBeenSet = true; m_cacheNodeType = value; }

    /**
     * <p>The cache node type for the reserved cache nodes.</p> <p>Valid node types are
     * as follows:</p> <ul> <li>General purpose: <ul> <li>Current generation:
     * <code>cache.t2.micro</code>, <code>cache.t2.small</code>,
     * <code>cache.t2.medium</code>, <code>cache.m3.medium</code>,
     * <code>cache.m3.large</code>, <code>cache.m3.xlarge</code>,
     * <code>cache.m3.2xlarge</code></li> <li>Previous generation:
     * <code>cache.t1.micro</code>, <code>cache.m1.small</code>,
     * <code>cache.m1.medium</code>, <code>cache.m1.large</code>,
     * <code>cache.m1.xlarge</code></li> </ul></li> <li>Compute optimized:
     * <code>cache.c1.xlarge</code></li> <li>Memory optimized <ul> <li>Current
     * generation: <code>cache.r3.large</code>, <code>cache.r3.xlarge</code>,
     * <code>cache.r3.2xlarge</code>, <code>cache.r3.4xlarge</code>,
     * <code>cache.r3.8xlarge</code></li> <li>Previous generation:
     * <code>cache.m2.xlarge</code>, <code>cache.m2.2xlarge</code>,
     * <code>cache.m2.4xlarge</code></li> </ul></li> </ul> <p><b>Notes:</b></p> <ul>
     * <li>All t2 instances are created in an Amazon Virtual Private Cloud (VPC).</li>
     * <li>Redis backup/restore is not supported for t2 instances.</li> <li>Redis
     * Append-only files (AOF) functionality is not supported for t1 or t2
     * instances.</li> </ul> <p>For a complete listing of cache node types and
     * specifications, see <a href="http://aws.amazon.com/elasticache/details">Amazon
     * ElastiCache Product Features and Details</a> and <a
     * href="http://docs.aws.amazon.com/AmazonElastiCache/latest/UserGuide/CacheParameterGroups.Memcached.html#CacheParameterGroups.Memcached.NodeSpecific">Cache
     * Node Type-Specific Parameters for Memcached</a> or <a
     * href="http://docs.aws.amazon.com/AmazonElastiCache/latest/UserGuide/CacheParameterGroups.Redis.html#CacheParameterGroups.Redis.NodeSpecific">Cache
     * Node Type-Specific Parameters for Redis</a>. </p>
     */
    inline void SetCacheNodeType(const char* value) { m_cacheNodeTypeHasBeenSet = true; m_cacheNodeType.assign(value); }

    /**
     * <p>The cache node type for the reserved cache nodes.</p> <p>Valid node types are
     * as follows:</p> <ul> <li>General purpose: <ul> <li>Current generation:
     * <code>cache.t2.micro</code>, <code>cache.t2.small</code>,
     * <code>cache.t2.medium</code>, <code>cache.m3.medium</code>,
     * <code>cache.m3.large</code>, <code>cache.m3.xlarge</code>,
     * <code>cache.m3.2xlarge</code></li> <li>Previous generation:
     * <code>cache.t1.micro</code>, <code>cache.m1.small</code>,
     * <code>cache.m1.medium</code>, <code>cache.m1.large</code>,
     * <code>cache.m1.xlarge</code></li> </ul></li> <li>Compute optimized:
     * <code>cache.c1.xlarge</code></li> <li>Memory optimized <ul> <li>Current
     * generation: <code>cache.r3.large</code>, <code>cache.r3.xlarge</code>,
     * <code>cache.r3.2xlarge</code>, <code>cache.r3.4xlarge</code>,
     * <code>cache.r3.8xlarge</code></li> <li>Previous generation:
     * <code>cache.m2.xlarge</code>, <code>cache.m2.2xlarge</code>,
     * <code>cache.m2.4xlarge</code></li> </ul></li> </ul> <p><b>Notes:</b></p> <ul>
     * <li>All t2 instances are created in an Amazon Virtual Private Cloud (VPC).</li>
     * <li>Redis backup/restore is not supported for t2 instances.</li> <li>Redis
     * Append-only files (AOF) functionality is not supported for t1 or t2
     * instances.</li> </ul> <p>For a complete listing of cache node types and
     * specifications, see <a href="http://aws.amazon.com/elasticache/details">Amazon
     * ElastiCache Product Features and Details</a> and <a
     * href="http://docs.aws.amazon.com/AmazonElastiCache/latest/UserGuide/CacheParameterGroups.Memcached.html#CacheParameterGroups.Memcached.NodeSpecific">Cache
     * Node Type-Specific Parameters for Memcached</a> or <a
     * href="http://docs.aws.amazon.com/AmazonElastiCache/latest/UserGuide/CacheParameterGroups.Redis.html#CacheParameterGroups.Redis.NodeSpecific">Cache
     * Node Type-Specific Parameters for Redis</a>. </p>
     */
    inline ReservedCacheNode& WithCacheNodeType(const Aws::String& value) { SetCacheNodeType(value); return *this;}

    /**
     * <p>The cache node type for the reserved cache nodes.</p> <p>Valid node types are
     * as follows:</p> <ul> <li>General purpose: <ul> <li>Current generation:
     * <code>cache.t2.micro</code>, <code>cache.t2.small</code>,
     * <code>cache.t2.medium</code>, <code>cache.m3.medium</code>,
     * <code>cache.m3.large</code>, <code>cache.m3.xlarge</code>,
     * <code>cache.m3.2xlarge</code></li> <li>Previous generation:
     * <code>cache.t1.micro</code>, <code>cache.m1.small</code>,
     * <code>cache.m1.medium</code>, <code>cache.m1.large</code>,
     * <code>cache.m1.xlarge</code></li> </ul></li> <li>Compute optimized:
     * <code>cache.c1.xlarge</code></li> <li>Memory optimized <ul> <li>Current
     * generation: <code>cache.r3.large</code>, <code>cache.r3.xlarge</code>,
     * <code>cache.r3.2xlarge</code>, <code>cache.r3.4xlarge</code>,
     * <code>cache.r3.8xlarge</code></li> <li>Previous generation:
     * <code>cache.m2.xlarge</code>, <code>cache.m2.2xlarge</code>,
     * <code>cache.m2.4xlarge</code></li> </ul></li> </ul> <p><b>Notes:</b></p> <ul>
     * <li>All t2 instances are created in an Amazon Virtual Private Cloud (VPC).</li>
     * <li>Redis backup/restore is not supported for t2 instances.</li> <li>Redis
     * Append-only files (AOF) functionality is not supported for t1 or t2
     * instances.</li> </ul> <p>For a complete listing of cache node types and
     * specifications, see <a href="http://aws.amazon.com/elasticache/details">Amazon
     * ElastiCache Product Features and Details</a> and <a
     * href="http://docs.aws.amazon.com/AmazonElastiCache/latest/UserGuide/CacheParameterGroups.Memcached.html#CacheParameterGroups.Memcached.NodeSpecific">Cache
     * Node Type-Specific Parameters for Memcached</a> or <a
     * href="http://docs.aws.amazon.com/AmazonElastiCache/latest/UserGuide/CacheParameterGroups.Redis.html#CacheParameterGroups.Redis.NodeSpecific">Cache
     * Node Type-Specific Parameters for Redis</a>. </p>
     */
    inline ReservedCacheNode& WithCacheNodeType(Aws::String&& value) { SetCacheNodeType(value); return *this;}

    /**
     * <p>The cache node type for the reserved cache nodes.</p> <p>Valid node types are
     * as follows:</p> <ul> <li>General purpose: <ul> <li>Current generation:
     * <code>cache.t2.micro</code>, <code>cache.t2.small</code>,
     * <code>cache.t2.medium</code>, <code>cache.m3.medium</code>,
     * <code>cache.m3.large</code>, <code>cache.m3.xlarge</code>,
     * <code>cache.m3.2xlarge</code></li> <li>Previous generation:
     * <code>cache.t1.micro</code>, <code>cache.m1.small</code>,
     * <code>cache.m1.medium</code>, <code>cache.m1.large</code>,
     * <code>cache.m1.xlarge</code></li> </ul></li> <li>Compute optimized:
     * <code>cache.c1.xlarge</code></li> <li>Memory optimized <ul> <li>Current
     * generation: <code>cache.r3.large</code>, <code>cache.r3.xlarge</code>,
     * <code>cache.r3.2xlarge</code>, <code>cache.r3.4xlarge</code>,
     * <code>cache.r3.8xlarge</code></li> <li>Previous generation:
     * <code>cache.m2.xlarge</code>, <code>cache.m2.2xlarge</code>,
     * <code>cache.m2.4xlarge</code></li> </ul></li> </ul> <p><b>Notes:</b></p> <ul>
     * <li>All t2 instances are created in an Amazon Virtual Private Cloud (VPC).</li>
     * <li>Redis backup/restore is not supported for t2 instances.</li> <li>Redis
     * Append-only files (AOF) functionality is not supported for t1 or t2
     * instances.</li> </ul> <p>For a complete listing of cache node types and
     * specifications, see <a href="http://aws.amazon.com/elasticache/details">Amazon
     * ElastiCache Product Features and Details</a> and <a
     * href="http://docs.aws.amazon.com/AmazonElastiCache/latest/UserGuide/CacheParameterGroups.Memcached.html#CacheParameterGroups.Memcached.NodeSpecific">Cache
     * Node Type-Specific Parameters for Memcached</a> or <a
     * href="http://docs.aws.amazon.com/AmazonElastiCache/latest/UserGuide/CacheParameterGroups.Redis.html#CacheParameterGroups.Redis.NodeSpecific">Cache
     * Node Type-Specific Parameters for Redis</a>. </p>
     */
    inline ReservedCacheNode& WithCacheNodeType(const char* value) { SetCacheNodeType(value); return *this;}

    /**
     * <p>The time the reservation started.</p>
     */
    inline double GetStartTime() const{ return m_startTime; }

    /**
     * <p>The time the reservation started.</p>
     */
    inline void SetStartTime(double value) { m_startTimeHasBeenSet = true; m_startTime = value; }

    /**
     * <p>The time the reservation started.</p>
     */
    inline ReservedCacheNode& WithStartTime(double value) { SetStartTime(value); return *this;}

    /**
     * <p>The duration of the reservation in seconds.</p>
     */
    inline long GetDuration() const{ return m_duration; }

    /**
     * <p>The duration of the reservation in seconds.</p>
     */
    inline void SetDuration(long value) { m_durationHasBeenSet = true; m_duration = value; }

    /**
     * <p>The duration of the reservation in seconds.</p>
     */
    inline ReservedCacheNode& WithDuration(long value) { SetDuration(value); return *this;}

    /**
     * <p>The fixed price charged for this reserved cache node.</p>
     */
    inline double GetFixedPrice() const{ return m_fixedPrice; }

    /**
     * <p>The fixed price charged for this reserved cache node.</p>
     */
    inline void SetFixedPrice(double value) { m_fixedPriceHasBeenSet = true; m_fixedPrice = value; }

    /**
     * <p>The fixed price charged for this reserved cache node.</p>
     */
    inline ReservedCacheNode& WithFixedPrice(double value) { SetFixedPrice(value); return *this;}

    /**
     * <p>The hourly price charged for this reserved cache node.</p>
     */
    inline double GetUsagePrice() const{ return m_usagePrice; }

    /**
     * <p>The hourly price charged for this reserved cache node.</p>
     */
    inline void SetUsagePrice(double value) { m_usagePriceHasBeenSet = true; m_usagePrice = value; }

    /**
     * <p>The hourly price charged for this reserved cache node.</p>
     */
    inline ReservedCacheNode& WithUsagePrice(double value) { SetUsagePrice(value); return *this;}

    /**
     * <p>The number of cache nodes that have been reserved.</p>
     */
    inline long GetCacheNodeCount() const{ return m_cacheNodeCount; }

    /**
     * <p>The number of cache nodes that have been reserved.</p>
     */
    inline void SetCacheNodeCount(long value) { m_cacheNodeCountHasBeenSet = true; m_cacheNodeCount = value; }

    /**
     * <p>The number of cache nodes that have been reserved.</p>
     */
    inline ReservedCacheNode& WithCacheNodeCount(long value) { SetCacheNodeCount(value); return *this;}

    /**
     * <p>The description of the reserved cache node.</p>
     */
    inline const Aws::String& GetProductDescription() const{ return m_productDescription; }

    /**
     * <p>The description of the reserved cache node.</p>
     */
    inline void SetProductDescription(const Aws::String& value) { m_productDescriptionHasBeenSet = true; m_productDescription = value; }

    /**
     * <p>The description of the reserved cache node.</p>
     */
    inline void SetProductDescription(Aws::String&& value) { m_productDescriptionHasBeenSet = true; m_productDescription = value; }

    /**
     * <p>The description of the reserved cache node.</p>
     */
    inline void SetProductDescription(const char* value) { m_productDescriptionHasBeenSet = true; m_productDescription.assign(value); }

    /**
     * <p>The description of the reserved cache node.</p>
     */
    inline ReservedCacheNode& WithProductDescription(const Aws::String& value) { SetProductDescription(value); return *this;}

    /**
     * <p>The description of the reserved cache node.</p>
     */
    inline ReservedCacheNode& WithProductDescription(Aws::String&& value) { SetProductDescription(value); return *this;}

    /**
     * <p>The description of the reserved cache node.</p>
     */
    inline ReservedCacheNode& WithProductDescription(const char* value) { SetProductDescription(value); return *this;}

    /**
     * <p>The offering type of this reserved cache node.</p>
     */
    inline const Aws::String& GetOfferingType() const{ return m_offeringType; }

    /**
     * <p>The offering type of this reserved cache node.</p>
     */
    inline void SetOfferingType(const Aws::String& value) { m_offeringTypeHasBeenSet = true; m_offeringType = value; }

    /**
     * <p>The offering type of this reserved cache node.</p>
     */
    inline void SetOfferingType(Aws::String&& value) { m_offeringTypeHasBeenSet = true; m_offeringType = value; }

    /**
     * <p>The offering type of this reserved cache node.</p>
     */
    inline void SetOfferingType(const char* value) { m_offeringTypeHasBeenSet = true; m_offeringType.assign(value); }

    /**
     * <p>The offering type of this reserved cache node.</p>
     */
    inline ReservedCacheNode& WithOfferingType(const Aws::String& value) { SetOfferingType(value); return *this;}

    /**
     * <p>The offering type of this reserved cache node.</p>
     */
    inline ReservedCacheNode& WithOfferingType(Aws::String&& value) { SetOfferingType(value); return *this;}

    /**
     * <p>The offering type of this reserved cache node.</p>
     */
    inline ReservedCacheNode& WithOfferingType(const char* value) { SetOfferingType(value); return *this;}

    /**
     * <p>The state of the reserved cache node.</p>
     */
    inline const Aws::String& GetState() const{ return m_state; }

    /**
     * <p>The state of the reserved cache node.</p>
     */
    inline void SetState(const Aws::String& value) { m_stateHasBeenSet = true; m_state = value; }

    /**
     * <p>The state of the reserved cache node.</p>
     */
    inline void SetState(Aws::String&& value) { m_stateHasBeenSet = true; m_state = value; }

    /**
     * <p>The state of the reserved cache node.</p>
     */
    inline void SetState(const char* value) { m_stateHasBeenSet = true; m_state.assign(value); }

    /**
     * <p>The state of the reserved cache node.</p>
     */
    inline ReservedCacheNode& WithState(const Aws::String& value) { SetState(value); return *this;}

    /**
     * <p>The state of the reserved cache node.</p>
     */
    inline ReservedCacheNode& WithState(Aws::String&& value) { SetState(value); return *this;}

    /**
     * <p>The state of the reserved cache node.</p>
     */
    inline ReservedCacheNode& WithState(const char* value) { SetState(value); return *this;}

    /**
     * <p>The recurring price charged to run this reserved cache node.</p>
     */
    inline const Aws::Vector<RecurringCharge>& GetRecurringCharges() const{ return m_recurringCharges; }

    /**
     * <p>The recurring price charged to run this reserved cache node.</p>
     */
    inline void SetRecurringCharges(const Aws::Vector<RecurringCharge>& value) { m_recurringChargesHasBeenSet = true; m_recurringCharges = value; }

    /**
     * <p>The recurring price charged to run this reserved cache node.</p>
     */
    inline void SetRecurringCharges(Aws::Vector<RecurringCharge>&& value) { m_recurringChargesHasBeenSet = true; m_recurringCharges = value; }

    /**
     * <p>The recurring price charged to run this reserved cache node.</p>
     */
    inline ReservedCacheNode& WithRecurringCharges(const Aws::Vector<RecurringCharge>& value) { SetRecurringCharges(value); return *this;}

    /**
     * <p>The recurring price charged to run this reserved cache node.</p>
     */
    inline ReservedCacheNode& WithRecurringCharges(Aws::Vector<RecurringCharge>&& value) { SetRecurringCharges(value); return *this;}

    /**
     * <p>The recurring price charged to run this reserved cache node.</p>
     */
    inline ReservedCacheNode& AddRecurringCharges(const RecurringCharge& value) { m_recurringChargesHasBeenSet = true; m_recurringCharges.push_back(value); return *this; }

    /**
     * <p>The recurring price charged to run this reserved cache node.</p>
     */
    inline ReservedCacheNode& AddRecurringCharges(RecurringCharge&& value) { m_recurringChargesHasBeenSet = true; m_recurringCharges.push_back(value); return *this; }

  private:
    Aws::String m_reservedCacheNodeId;
    bool m_reservedCacheNodeIdHasBeenSet;
    Aws::String m_reservedCacheNodesOfferingId;
    bool m_reservedCacheNodesOfferingIdHasBeenSet;
    Aws::String m_cacheNodeType;
    bool m_cacheNodeTypeHasBeenSet;
    double m_startTime;
    bool m_startTimeHasBeenSet;
    long m_duration;
    bool m_durationHasBeenSet;
    double m_fixedPrice;
    bool m_fixedPriceHasBeenSet;
    double m_usagePrice;
    bool m_usagePriceHasBeenSet;
    long m_cacheNodeCount;
    bool m_cacheNodeCountHasBeenSet;
    Aws::String m_productDescription;
    bool m_productDescriptionHasBeenSet;
    Aws::String m_offeringType;
    bool m_offeringTypeHasBeenSet;
    Aws::String m_state;
    bool m_stateHasBeenSet;
    Aws::Vector<RecurringCharge> m_recurringCharges;
    bool m_recurringChargesHasBeenSet;
  };

} // namespace Model
} // namespace ElastiCache
} // namespace Aws