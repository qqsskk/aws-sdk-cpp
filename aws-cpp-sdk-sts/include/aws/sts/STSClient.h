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
#include <aws/sts/STS_EXPORTS.h>
#include <aws/sts/STSErrors.h>
#include <aws/core/client/AWSError.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/client/AWSClient.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/sts/model/AssumeRoleResult.h>
#include <aws/sts/model/AssumeRoleWithSAMLResult.h>
#include <aws/sts/model/AssumeRoleWithWebIdentityResult.h>
#include <aws/sts/model/DecodeAuthorizationMessageResult.h>
#include <aws/sts/model/GetFederationTokenResult.h>
#include <aws/sts/model/GetSessionTokenResult.h>
#include <aws/core/client/AsyncCallerContext.h>
#include <aws/core/http/HttpTypes.h>
#include <future>
#include <functional>

namespace Aws
{

namespace Http
{
  class HttpClient;
  class HttpClientFactory;
} // namespace Http

namespace Utils
{
  template< typename R, typename E> class Outcome;

namespace Threading
{
  class Executor;
} // namespace Threading

namespace Xml
{
  class XmlDocument;
} // namespace Xml
} // namespace Utils

namespace Auth
{
  class AWSCredentials;
  class AWSCredentialsProvider;
} // namespace Auth

namespace Client
{
  class RetryStrategy;
} // namespace Client

namespace STS
{

namespace Model
{
        class AssumeRoleRequest;
        class AssumeRoleWithSAMLRequest;
        class AssumeRoleWithWebIdentityRequest;
        class DecodeAuthorizationMessageRequest;
        class GetFederationTokenRequest;
        class GetSessionTokenRequest;

        typedef Aws::Utils::Outcome<AssumeRoleResult, Aws::Client::AWSError<STSErrors>> AssumeRoleOutcome;
        typedef Aws::Utils::Outcome<AssumeRoleWithSAMLResult, Aws::Client::AWSError<STSErrors>> AssumeRoleWithSAMLOutcome;
        typedef Aws::Utils::Outcome<AssumeRoleWithWebIdentityResult, Aws::Client::AWSError<STSErrors>> AssumeRoleWithWebIdentityOutcome;
        typedef Aws::Utils::Outcome<DecodeAuthorizationMessageResult, Aws::Client::AWSError<STSErrors>> DecodeAuthorizationMessageOutcome;
        typedef Aws::Utils::Outcome<GetFederationTokenResult, Aws::Client::AWSError<STSErrors>> GetFederationTokenOutcome;
        typedef Aws::Utils::Outcome<GetSessionTokenResult, Aws::Client::AWSError<STSErrors>> GetSessionTokenOutcome;

        typedef std::future<AssumeRoleOutcome> AssumeRoleOutcomeCallable;
        typedef std::future<AssumeRoleWithSAMLOutcome> AssumeRoleWithSAMLOutcomeCallable;
        typedef std::future<AssumeRoleWithWebIdentityOutcome> AssumeRoleWithWebIdentityOutcomeCallable;
        typedef std::future<DecodeAuthorizationMessageOutcome> DecodeAuthorizationMessageOutcomeCallable;
        typedef std::future<GetFederationTokenOutcome> GetFederationTokenOutcomeCallable;
        typedef std::future<GetSessionTokenOutcome> GetSessionTokenOutcomeCallable;
} // namespace Model

  class STSClient;

    typedef std::function<void(const STSClient*, const Model::AssumeRoleRequest&, const Model::AssumeRoleOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > AssumeRoleResponseReceivedHandler;
    typedef std::function<void(const STSClient*, const Model::AssumeRoleWithSAMLRequest&, const Model::AssumeRoleWithSAMLOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > AssumeRoleWithSAMLResponseReceivedHandler;
    typedef std::function<void(const STSClient*, const Model::AssumeRoleWithWebIdentityRequest&, const Model::AssumeRoleWithWebIdentityOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > AssumeRoleWithWebIdentityResponseReceivedHandler;
    typedef std::function<void(const STSClient*, const Model::DecodeAuthorizationMessageRequest&, const Model::DecodeAuthorizationMessageOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DecodeAuthorizationMessageResponseReceivedHandler;
    typedef std::function<void(const STSClient*, const Model::GetFederationTokenRequest&, const Model::GetFederationTokenOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GetFederationTokenResponseReceivedHandler;
    typedef std::function<void(const STSClient*, const Model::GetSessionTokenRequest&, const Model::GetSessionTokenOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GetSessionTokenResponseReceivedHandler;

  /**
   * <fullname>AWS Security Token Service</fullname> <p>The AWS Security Token
   * Service (STS) is a web service that enables you to request temporary,
   * limited-privilege credentials for AWS Identity and Access Management (IAM) users
   * or for users that you authenticate (federated users). This guide provides
   * descriptions of the STS API. For more detailed information about using this
   * service, go to <a
   * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/Welcome.html"
   * target="_blank">Using Temporary Security Credentials</a>. </p> <note> As an
   * alternative to using the API, you can use one of the AWS SDKs, which consist of
   * libraries and sample code for various programming languages and platforms (Java,
   * Ruby, .NET, iOS, Android, etc.). The SDKs provide a convenient way to create
   * programmatic access to STS. For example, the SDKs take care of cryptographically
   * signing requests, managing errors, and retrying requests automatically. For
   * information about the AWS SDKs, including how to download and install them, see
   * the <a href="http://aws.amazon.com/tools/">Tools for Amazon Web Services
   * page</a>. </note> <p>For information about setting up signatures and
   * authorization through the API, go to <a
   * href="http://docs.aws.amazon.com/general/latest/gr/signing_aws_api_requests.html"
   * target="_blank">Signing AWS API Requests</a> in the <i>AWS General
   * Reference</i>. For general information about the Query API, go to <a
   * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/IAM_UsingQueryAPI.html"
   * target="_blank">Making Query Requests</a> in <i>Using IAM</i>. For information
   * about using security tokens with other AWS products, go to <a
   * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/UsingTokens.html">Using
   * Temporary Security Credentials to Access AWS</a> in <i>Using Temporary Security
   * Credentials</i>. </p> <p>If you're new to AWS and need additional technical
   * information about a specific AWS product, you can find the product's technical
   * documentation at <a href="http://aws.amazon.com/documentation/"
   * target="_blank">http://aws.amazon.com/documentation/</a>. </p> <p>
   * <b>Endpoints</b> </p> <p>The AWS Security Token Service (STS) has a default
   * endpoint of https://sts.amazonaws.com that maps to the US East (N. Virginia)
   * region. Additional regions are available, but must first be activated in the AWS
   * Management Console before you can use a different region's endpoint. For more
   * information about activating a region for STS see <a
   * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/sts-enableregions.html">Activating
   * STS in a New Region</a> in the <i>Using Temporary Security Credentials</i>
   * guide. </p> <p>For information about STS endpoints, see <a
   * href="http://docs.aws.amazon.com/general/latest/gr/rande.html#sts_region">Regions
   * and Endpoints</a> in the <i>AWS General Reference</i>.</p> <p> <b>Recording API
   * requests</b> </p> <p>STS supports AWS CloudTrail, which is a service that
   * records AWS calls for your AWS account and delivers log files to an Amazon S3
   * bucket. By using information collected by CloudTrail, you can determine what
   * requests were successfully made to STS, who made the request, when it was made,
   * and so on. To learn more about CloudTrail, including how to turn it on and find
   * your log files, see the <a
   * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/what_is_cloud_trail_top_level.html">AWS
   * CloudTrail User Guide</a>.</p>
   */
  class AWS_STS_API STSClient : public Aws::Client::AWSXMLClient
  {
    public:
      typedef Aws::Client::AWSXMLClient BASECLASS;

       /**
        * Initializes client to use DefaultCredentialProviderChain, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        STSClient(const Client::ClientConfiguration& clientConfiguration = Client::ClientConfiguration());

       /**
        * Initializes client to use SimpleAWSCredentialsProvider, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        STSClient(const Auth::AWSCredentials& credentials, const Client::ClientConfiguration& clientConfiguration = Client::ClientConfiguration());

       /**
        * Initializes client to use specified credentials provider with specified client config. If http client factory is not supplied,
        * the default http client factory will be used
        */
        STSClient(const std::shared_ptr<Auth::AWSCredentialsProvider>& credentialsProvider,
            const Client::ClientConfiguration& clientConfiguration = Client::ClientConfiguration(),
            const std::shared_ptr<Http::HttpClientFactory const>& httpClientFactory = nullptr);

        virtual ~STSClient();

        /**
         * <p>Returns a set of temporary security credentials (consisting of an access key
         * ID, a secret access key, and a security token) that you can use to access AWS
         * resources that you might not normally have access to. Typically, you use
         * <code>AssumeRole</code> for cross-account access or federation. </p>
         * <p><b>Important:</b> You cannot call <code>AssumeRole</code> by using AWS
         * account credentials; access will be denied. You must use IAM user credentials or
         * temporary security credentials to call <code>AssumeRole</code>. </p> <p>For
         * cross-account access, imagine that you own multiple accounts and need to access
         * resources in each account. You could create long-term credentials in each
         * account to access those resources. However, managing all those credentials and
         * remembering which one can access which account can be time consuming. Instead,
         * you can create one set of long-term credentials in one account and then use
         * temporary security credentials to access all the other accounts by assuming
         * roles in those accounts. For more information about roles, see <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/roles-toplevel.html">IAM
         * Roles (Delegation and Federation)</a> in <i>Using IAM</i>. </p> <p>For
         * federation, you can, for example, grant single sign-on access to the AWS
         * Management Console. If you already have an identity and authentication system in
         * your corporate network, you don't have to recreate user identities in AWS in
         * order to grant those user identities access to AWS. Instead, after a user has
         * been authenticated, you call <code>AssumeRole</code> (and specify the role with
         * the appropriate permissions) to get temporary security credentials for that
         * user. With those temporary security credentials, you construct a sign-in URL
         * that users can use to access the console. For more information, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/STSUseCases.html">Scenarios
         * for Granting Temporary Access</a> in <i>Using Temporary Security
         * Credentials</i>. </p> <p>The temporary security credentials are valid for the
         * duration that you specified when calling <code>AssumeRole</code>, which can be
         * from 900 seconds (15 minutes) to 3600 seconds (1 hour). The default is 1 hour.
         * </p> <p>Optionally, you can pass an IAM access policy to this operation. If you
         * choose not to pass a policy, the temporary security credentials that are
         * returned by the operation have the permissions that are defined in the access
         * policy of the role that is being assumed. If you pass a policy to this
         * operation, the temporary security credentials that are returned by the operation
         * have the permissions that are allowed by both the access policy of the role that
         * is being assumed, <i><b>and</b></i> the policy that you pass. This gives you a
         * way to further restrict the permissions for the resulting temporary security
         * credentials. You cannot use the passed policy to grant permissions that are in
         * excess of those allowed by the access policy of the role that is being assumed.
         * For more information, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/permissions-assume-role.html">Permissions
         * for AssumeRole, AssumeRoleWithSAML, and AssumeRoleWithWebIdentity</a> in
         * <i>Using Temporary Security Credentials</i>.</p> <p>To assume a role, your AWS
         * account must be trusted by the role. The trust relationship is defined in the
         * role's trust policy when the role is created. You must also have a policy that
         * allows you to call <code>sts:AssumeRole</code>. </p> <p> <b>Using MFA with
         * AssumeRole</b> </p> <p>You can optionally include multi-factor authentication
         * (MFA) information when you call <code>AssumeRole</code>. This is useful for
         * cross-account scenarios in which you want to make sure that the user who is
         * assuming the role has been authenticated using an AWS MFA device. In that
         * scenario, the trust policy of the role being assumed includes a condition that
         * tests for MFA authentication; if the caller does not include valid MFA
         * information, the request to assume the role is denied. The condition in a trust
         * policy that tests for MFA authentication might look like the following
         * example.</p> <p> <code>"Condition": {"Bool": {"aws:MultiFactorAuthPresent":
         * true}}</code> </p> <p>For more information, see <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/MFAProtectedAPI.html">Configuring
         * MFA-Protected API Access</a> in <i>Using IAM</i> guide.</p> <p>To use MFA with
         * <code>AssumeRole</code>, you pass values for the <code>SerialNumber</code> and
         * <code>TokenCode</code> parameters. The <code>SerialNumber</code> value
         * identifies the user's hardware or virtual MFA device. The <code>TokenCode</code>
         * is the time-based one-time password (TOTP) that the MFA devices produces. </p>
         * <member name="RoleArn" target="arnType"></member> <member name="RoleSessionName"
         * target="userNameType"></member> <member name="Policy"
         * target="sessionPolicyDocumentType"></member> <member name="DurationSeconds"
         * target="roleDurationSecondsType"></member> <member name="ExternalId"
         * target="externalIdType"></member>
         */
        virtual Model::AssumeRoleOutcome AssumeRole(const Model::AssumeRoleRequest& request) const;

        /**
         * <p>Returns a set of temporary security credentials (consisting of an access key
         * ID, a secret access key, and a security token) that you can use to access AWS
         * resources that you might not normally have access to. Typically, you use
         * <code>AssumeRole</code> for cross-account access or federation. </p>
         * <p><b>Important:</b> You cannot call <code>AssumeRole</code> by using AWS
         * account credentials; access will be denied. You must use IAM user credentials or
         * temporary security credentials to call <code>AssumeRole</code>. </p> <p>For
         * cross-account access, imagine that you own multiple accounts and need to access
         * resources in each account. You could create long-term credentials in each
         * account to access those resources. However, managing all those credentials and
         * remembering which one can access which account can be time consuming. Instead,
         * you can create one set of long-term credentials in one account and then use
         * temporary security credentials to access all the other accounts by assuming
         * roles in those accounts. For more information about roles, see <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/roles-toplevel.html">IAM
         * Roles (Delegation and Federation)</a> in <i>Using IAM</i>. </p> <p>For
         * federation, you can, for example, grant single sign-on access to the AWS
         * Management Console. If you already have an identity and authentication system in
         * your corporate network, you don't have to recreate user identities in AWS in
         * order to grant those user identities access to AWS. Instead, after a user has
         * been authenticated, you call <code>AssumeRole</code> (and specify the role with
         * the appropriate permissions) to get temporary security credentials for that
         * user. With those temporary security credentials, you construct a sign-in URL
         * that users can use to access the console. For more information, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/STSUseCases.html">Scenarios
         * for Granting Temporary Access</a> in <i>Using Temporary Security
         * Credentials</i>. </p> <p>The temporary security credentials are valid for the
         * duration that you specified when calling <code>AssumeRole</code>, which can be
         * from 900 seconds (15 minutes) to 3600 seconds (1 hour). The default is 1 hour.
         * </p> <p>Optionally, you can pass an IAM access policy to this operation. If you
         * choose not to pass a policy, the temporary security credentials that are
         * returned by the operation have the permissions that are defined in the access
         * policy of the role that is being assumed. If you pass a policy to this
         * operation, the temporary security credentials that are returned by the operation
         * have the permissions that are allowed by both the access policy of the role that
         * is being assumed, <i><b>and</b></i> the policy that you pass. This gives you a
         * way to further restrict the permissions for the resulting temporary security
         * credentials. You cannot use the passed policy to grant permissions that are in
         * excess of those allowed by the access policy of the role that is being assumed.
         * For more information, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/permissions-assume-role.html">Permissions
         * for AssumeRole, AssumeRoleWithSAML, and AssumeRoleWithWebIdentity</a> in
         * <i>Using Temporary Security Credentials</i>.</p> <p>To assume a role, your AWS
         * account must be trusted by the role. The trust relationship is defined in the
         * role's trust policy when the role is created. You must also have a policy that
         * allows you to call <code>sts:AssumeRole</code>. </p> <p> <b>Using MFA with
         * AssumeRole</b> </p> <p>You can optionally include multi-factor authentication
         * (MFA) information when you call <code>AssumeRole</code>. This is useful for
         * cross-account scenarios in which you want to make sure that the user who is
         * assuming the role has been authenticated using an AWS MFA device. In that
         * scenario, the trust policy of the role being assumed includes a condition that
         * tests for MFA authentication; if the caller does not include valid MFA
         * information, the request to assume the role is denied. The condition in a trust
         * policy that tests for MFA authentication might look like the following
         * example.</p> <p> <code>"Condition": {"Bool": {"aws:MultiFactorAuthPresent":
         * true}}</code> </p> <p>For more information, see <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/MFAProtectedAPI.html">Configuring
         * MFA-Protected API Access</a> in <i>Using IAM</i> guide.</p> <p>To use MFA with
         * <code>AssumeRole</code>, you pass values for the <code>SerialNumber</code> and
         * <code>TokenCode</code> parameters. The <code>SerialNumber</code> value
         * identifies the user's hardware or virtual MFA device. The <code>TokenCode</code>
         * is the time-based one-time password (TOTP) that the MFA devices produces. </p>
         * <member name="RoleArn" target="arnType"></member> <member name="RoleSessionName"
         * target="userNameType"></member> <member name="Policy"
         * target="sessionPolicyDocumentType"></member> <member name="DurationSeconds"
         * target="roleDurationSecondsType"></member> <member name="ExternalId"
         * target="externalIdType"></member>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::AssumeRoleOutcomeCallable AssumeRoleCallable(const Model::AssumeRoleRequest& request) const;

        /**
         * <p>Returns a set of temporary security credentials (consisting of an access key
         * ID, a secret access key, and a security token) that you can use to access AWS
         * resources that you might not normally have access to. Typically, you use
         * <code>AssumeRole</code> for cross-account access or federation. </p>
         * <p><b>Important:</b> You cannot call <code>AssumeRole</code> by using AWS
         * account credentials; access will be denied. You must use IAM user credentials or
         * temporary security credentials to call <code>AssumeRole</code>. </p> <p>For
         * cross-account access, imagine that you own multiple accounts and need to access
         * resources in each account. You could create long-term credentials in each
         * account to access those resources. However, managing all those credentials and
         * remembering which one can access which account can be time consuming. Instead,
         * you can create one set of long-term credentials in one account and then use
         * temporary security credentials to access all the other accounts by assuming
         * roles in those accounts. For more information about roles, see <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/roles-toplevel.html">IAM
         * Roles (Delegation and Federation)</a> in <i>Using IAM</i>. </p> <p>For
         * federation, you can, for example, grant single sign-on access to the AWS
         * Management Console. If you already have an identity and authentication system in
         * your corporate network, you don't have to recreate user identities in AWS in
         * order to grant those user identities access to AWS. Instead, after a user has
         * been authenticated, you call <code>AssumeRole</code> (and specify the role with
         * the appropriate permissions) to get temporary security credentials for that
         * user. With those temporary security credentials, you construct a sign-in URL
         * that users can use to access the console. For more information, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/STSUseCases.html">Scenarios
         * for Granting Temporary Access</a> in <i>Using Temporary Security
         * Credentials</i>. </p> <p>The temporary security credentials are valid for the
         * duration that you specified when calling <code>AssumeRole</code>, which can be
         * from 900 seconds (15 minutes) to 3600 seconds (1 hour). The default is 1 hour.
         * </p> <p>Optionally, you can pass an IAM access policy to this operation. If you
         * choose not to pass a policy, the temporary security credentials that are
         * returned by the operation have the permissions that are defined in the access
         * policy of the role that is being assumed. If you pass a policy to this
         * operation, the temporary security credentials that are returned by the operation
         * have the permissions that are allowed by both the access policy of the role that
         * is being assumed, <i><b>and</b></i> the policy that you pass. This gives you a
         * way to further restrict the permissions for the resulting temporary security
         * credentials. You cannot use the passed policy to grant permissions that are in
         * excess of those allowed by the access policy of the role that is being assumed.
         * For more information, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/permissions-assume-role.html">Permissions
         * for AssumeRole, AssumeRoleWithSAML, and AssumeRoleWithWebIdentity</a> in
         * <i>Using Temporary Security Credentials</i>.</p> <p>To assume a role, your AWS
         * account must be trusted by the role. The trust relationship is defined in the
         * role's trust policy when the role is created. You must also have a policy that
         * allows you to call <code>sts:AssumeRole</code>. </p> <p> <b>Using MFA with
         * AssumeRole</b> </p> <p>You can optionally include multi-factor authentication
         * (MFA) information when you call <code>AssumeRole</code>. This is useful for
         * cross-account scenarios in which you want to make sure that the user who is
         * assuming the role has been authenticated using an AWS MFA device. In that
         * scenario, the trust policy of the role being assumed includes a condition that
         * tests for MFA authentication; if the caller does not include valid MFA
         * information, the request to assume the role is denied. The condition in a trust
         * policy that tests for MFA authentication might look like the following
         * example.</p> <p> <code>"Condition": {"Bool": {"aws:MultiFactorAuthPresent":
         * true}}</code> </p> <p>For more information, see <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/MFAProtectedAPI.html">Configuring
         * MFA-Protected API Access</a> in <i>Using IAM</i> guide.</p> <p>To use MFA with
         * <code>AssumeRole</code>, you pass values for the <code>SerialNumber</code> and
         * <code>TokenCode</code> parameters. The <code>SerialNumber</code> value
         * identifies the user's hardware or virtual MFA device. The <code>TokenCode</code>
         * is the time-based one-time password (TOTP) that the MFA devices produces. </p>
         * <member name="RoleArn" target="arnType"></member> <member name="RoleSessionName"
         * target="userNameType"></member> <member name="Policy"
         * target="sessionPolicyDocumentType"></member> <member name="DurationSeconds"
         * target="roleDurationSecondsType"></member> <member name="ExternalId"
         * target="externalIdType"></member>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void AssumeRoleAsync(const Model::AssumeRoleRequest& request, const AssumeRoleResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Returns a set of temporary security credentials for users who have been
         * authenticated via a SAML authentication response. This operation provides a
         * mechanism for tying an enterprise identity store or directory to role-based AWS
         * access without user-specific credentials or configuration. </p> <p>The temporary
         * security credentials returned by this operation consist of an access key ID, a
         * secret access key, and a security token. Applications can use these temporary
         * security credentials to sign calls to AWS services. The credentials are valid
         * for the duration that you specified when calling
         * <code>AssumeRoleWithSAML</code>, which can be up to 3600 seconds (1 hour) or
         * until the time specified in the SAML authentication response's
         * <code>SessionNotOnOrAfter</code> value, whichever is shorter.</p> <note>The
         * maximum duration for a session is 1 hour, and the minimum duration is 15
         * minutes, even if values outside this range are specified. </note> <p>Optionally,
         * you can pass an IAM access policy to this operation. If you choose not to pass a
         * policy, the temporary security credentials that are returned by the operation
         * have the permissions that are defined in the access policy of the role that is
         * being assumed. If you pass a policy to this operation, the temporary security
         * credentials that are returned by the operation have the permissions that are
         * allowed by both the access policy of the role that is being assumed,
         * <i><b>and</b></i> the policy that you pass. This gives you a way to further
         * restrict the permissions for the resulting temporary security credentials. You
         * cannot use the passed policy to grant permissions that are in excess of those
         * allowed by the access policy of the role that is being assumed. For more
         * information, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/permissions-assume-role.html">Permissions
         * for AssumeRoleWithSAML</a> in <i>Using Temporary Security Credentials</i>.</p>
         * <p>Before your application can call <code>AssumeRoleWithSAML</code>, you must
         * configure your SAML identity provider (IdP) to issue the claims required by AWS.
         * Additionally, you must use AWS Identity and Access Management (IAM) to create a
         * SAML provider entity in your AWS account that represents your identity provider,
         * and create an IAM role that specifies this SAML provider in its trust policy.
         * </p> <p>Calling <code>AssumeRoleWithSAML</code> does not require the use of AWS
         * security credentials. The identity of the caller is validated by using keys in
         * the metadata document that is uploaded for the SAML provider entity for your
         * identity provider. </p> <p>For more information, see the following
         * resources:</p> <ul> <li> <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingSAML.html">Creating
         * Temporary Security Credentials for SAML Federation</a>. </li> <li> <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/idp-managing-identityproviders.html">SAML
         * Providers</a> in <i>Using IAM</i>. </li> <li> <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/create-role-saml-IdP-tasks.html">Configuring
         * a Relying Party and Claims</a> in <i>Using IAM</i>. </li> <li> <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/create-role-saml.html">Creating
         * a Role for SAML-Based Federation</a> in <i>Using IAM</i>. </li> </ul> <member
         * name="RoleArn" target="arnType"></member> <member name="SAMLAssertion"
         * target="SAMLAssertionType"></member> <member name="Policy"
         * target="sessionPolicyDocumentType"></member> <member name="DurationSeconds"
         * target="roleDurationSecondsType"></member>
         */
        virtual Model::AssumeRoleWithSAMLOutcome AssumeRoleWithSAML(const Model::AssumeRoleWithSAMLRequest& request) const;

        /**
         * <p>Returns a set of temporary security credentials for users who have been
         * authenticated via a SAML authentication response. This operation provides a
         * mechanism for tying an enterprise identity store or directory to role-based AWS
         * access without user-specific credentials or configuration. </p> <p>The temporary
         * security credentials returned by this operation consist of an access key ID, a
         * secret access key, and a security token. Applications can use these temporary
         * security credentials to sign calls to AWS services. The credentials are valid
         * for the duration that you specified when calling
         * <code>AssumeRoleWithSAML</code>, which can be up to 3600 seconds (1 hour) or
         * until the time specified in the SAML authentication response's
         * <code>SessionNotOnOrAfter</code> value, whichever is shorter.</p> <note>The
         * maximum duration for a session is 1 hour, and the minimum duration is 15
         * minutes, even if values outside this range are specified. </note> <p>Optionally,
         * you can pass an IAM access policy to this operation. If you choose not to pass a
         * policy, the temporary security credentials that are returned by the operation
         * have the permissions that are defined in the access policy of the role that is
         * being assumed. If you pass a policy to this operation, the temporary security
         * credentials that are returned by the operation have the permissions that are
         * allowed by both the access policy of the role that is being assumed,
         * <i><b>and</b></i> the policy that you pass. This gives you a way to further
         * restrict the permissions for the resulting temporary security credentials. You
         * cannot use the passed policy to grant permissions that are in excess of those
         * allowed by the access policy of the role that is being assumed. For more
         * information, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/permissions-assume-role.html">Permissions
         * for AssumeRoleWithSAML</a> in <i>Using Temporary Security Credentials</i>.</p>
         * <p>Before your application can call <code>AssumeRoleWithSAML</code>, you must
         * configure your SAML identity provider (IdP) to issue the claims required by AWS.
         * Additionally, you must use AWS Identity and Access Management (IAM) to create a
         * SAML provider entity in your AWS account that represents your identity provider,
         * and create an IAM role that specifies this SAML provider in its trust policy.
         * </p> <p>Calling <code>AssumeRoleWithSAML</code> does not require the use of AWS
         * security credentials. The identity of the caller is validated by using keys in
         * the metadata document that is uploaded for the SAML provider entity for your
         * identity provider. </p> <p>For more information, see the following
         * resources:</p> <ul> <li> <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingSAML.html">Creating
         * Temporary Security Credentials for SAML Federation</a>. </li> <li> <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/idp-managing-identityproviders.html">SAML
         * Providers</a> in <i>Using IAM</i>. </li> <li> <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/create-role-saml-IdP-tasks.html">Configuring
         * a Relying Party and Claims</a> in <i>Using IAM</i>. </li> <li> <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/create-role-saml.html">Creating
         * a Role for SAML-Based Federation</a> in <i>Using IAM</i>. </li> </ul> <member
         * name="RoleArn" target="arnType"></member> <member name="SAMLAssertion"
         * target="SAMLAssertionType"></member> <member name="Policy"
         * target="sessionPolicyDocumentType"></member> <member name="DurationSeconds"
         * target="roleDurationSecondsType"></member>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::AssumeRoleWithSAMLOutcomeCallable AssumeRoleWithSAMLCallable(const Model::AssumeRoleWithSAMLRequest& request) const;

        /**
         * <p>Returns a set of temporary security credentials for users who have been
         * authenticated via a SAML authentication response. This operation provides a
         * mechanism for tying an enterprise identity store or directory to role-based AWS
         * access without user-specific credentials or configuration. </p> <p>The temporary
         * security credentials returned by this operation consist of an access key ID, a
         * secret access key, and a security token. Applications can use these temporary
         * security credentials to sign calls to AWS services. The credentials are valid
         * for the duration that you specified when calling
         * <code>AssumeRoleWithSAML</code>, which can be up to 3600 seconds (1 hour) or
         * until the time specified in the SAML authentication response's
         * <code>SessionNotOnOrAfter</code> value, whichever is shorter.</p> <note>The
         * maximum duration for a session is 1 hour, and the minimum duration is 15
         * minutes, even if values outside this range are specified. </note> <p>Optionally,
         * you can pass an IAM access policy to this operation. If you choose not to pass a
         * policy, the temporary security credentials that are returned by the operation
         * have the permissions that are defined in the access policy of the role that is
         * being assumed. If you pass a policy to this operation, the temporary security
         * credentials that are returned by the operation have the permissions that are
         * allowed by both the access policy of the role that is being assumed,
         * <i><b>and</b></i> the policy that you pass. This gives you a way to further
         * restrict the permissions for the resulting temporary security credentials. You
         * cannot use the passed policy to grant permissions that are in excess of those
         * allowed by the access policy of the role that is being assumed. For more
         * information, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/permissions-assume-role.html">Permissions
         * for AssumeRoleWithSAML</a> in <i>Using Temporary Security Credentials</i>.</p>
         * <p>Before your application can call <code>AssumeRoleWithSAML</code>, you must
         * configure your SAML identity provider (IdP) to issue the claims required by AWS.
         * Additionally, you must use AWS Identity and Access Management (IAM) to create a
         * SAML provider entity in your AWS account that represents your identity provider,
         * and create an IAM role that specifies this SAML provider in its trust policy.
         * </p> <p>Calling <code>AssumeRoleWithSAML</code> does not require the use of AWS
         * security credentials. The identity of the caller is validated by using keys in
         * the metadata document that is uploaded for the SAML provider entity for your
         * identity provider. </p> <p>For more information, see the following
         * resources:</p> <ul> <li> <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingSAML.html">Creating
         * Temporary Security Credentials for SAML Federation</a>. </li> <li> <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/idp-managing-identityproviders.html">SAML
         * Providers</a> in <i>Using IAM</i>. </li> <li> <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/create-role-saml-IdP-tasks.html">Configuring
         * a Relying Party and Claims</a> in <i>Using IAM</i>. </li> <li> <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/create-role-saml.html">Creating
         * a Role for SAML-Based Federation</a> in <i>Using IAM</i>. </li> </ul> <member
         * name="RoleArn" target="arnType"></member> <member name="SAMLAssertion"
         * target="SAMLAssertionType"></member> <member name="Policy"
         * target="sessionPolicyDocumentType"></member> <member name="DurationSeconds"
         * target="roleDurationSecondsType"></member>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void AssumeRoleWithSAMLAsync(const Model::AssumeRoleWithSAMLRequest& request, const AssumeRoleWithSAMLResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Returns a set of temporary security credentials for users who have been
         * authenticated in a mobile or web application with a web identity provider, such
         * as Amazon Cognito, Login with Amazon, Facebook, Google, or any OpenID
         * Connect-compatible identity provider. </p> <note> <p>For mobile applications, we
         * recommend that you use Amazon Cognito. You can use Amazon Cognito with the <a
         * href="http://aws.amazon.com/sdkforios/">AWS SDK for iOS</a> and the <a
         * href="http://aws.amazon.com/sdkforandroid/">AWS SDK for Android</a> to uniquely
         * identify a user and supply the user with a consistent identity throughout the
         * lifetime of an application.</p> <p>To learn more about Amazon Cognito, see <a
         * href="http://docs.aws.amazon.com/mobile/sdkforandroid/developerguide/cognito-auth.html#d0e840">Amazon
         * Cognito Overview</a> in the <i>AWS SDK for Android Developer Guide</i> guide and
         * <a
         * href="http://docs.aws.amazon.com/mobile/sdkforios/developerguide/cognito-auth.html#d0e664">Amazon
         * Cognito Overview</a> in the <i>AWS SDK for iOS Developer Guide</i>.</p> </note>
         * <p>Calling <code>AssumeRoleWithWebIdentity</code> does not require the use of
         * AWS security credentials. Therefore, you can distribute an application (for
         * example, on mobile devices) that requests temporary security credentials without
         * including long-term AWS credentials in the application, and without deploying
         * server-based proxy services that use long-term AWS credentials. Instead, the
         * identity of the caller is validated by using a token from the web identity
         * provider. </p> <p>The temporary security credentials returned by this API
         * consist of an access key ID, a secret access key, and a security token.
         * Applications can use these temporary security credentials to sign calls to AWS
         * service APIs. The credentials are valid for the duration that you specified when
         * calling <code>AssumeRoleWithWebIdentity</code>, which can be from 900 seconds
         * (15 minutes) to 3600 seconds (1 hour). By default, the temporary security
         * credentials are valid for 1 hour. </p> <p>Optionally, you can pass an IAM access
         * policy to this operation. If you choose not to pass a policy, the temporary
         * security credentials that are returned by the operation have the permissions
         * that are defined in the access policy of the role that is being assumed. If you
         * pass a policy to this operation, the temporary security credentials that are
         * returned by the operation have the permissions that are allowed by both the
         * access policy of the role that is being assumed, <i><b>and</b></i> the policy
         * that you pass. This gives you a way to further restrict the permissions for the
         * resulting temporary security credentials. You cannot use the passed policy to
         * grant permissions that are in excess of those allowed by the access policy of
         * the role that is being assumed. For more information, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/permissions-assume-role.html">Permissions
         * for AssumeRoleWithWebIdentity</a>.</p> <p>Before your application can call
         * <code>AssumeRoleWithWebIdentity</code>, you must have an identity token from a
         * supported identity provider and create a role that the application can assume.
         * The role that your application assumes must trust the identity provider that is
         * associated with the identity token. In other words, the identity provider must
         * be specified in the role's trust policy. </p> <p>For more information about how
         * to use web identity federation and the <code>AssumeRoleWithWebIdentity</code>
         * API, see the following resources: </p> <ul> <li> <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/STSUseCases.html#MobileApplication-KnownProvider">
         * Creating a Mobile Application with Third-Party Sign-In</a> and <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingWIF.html"> Creating
         * Temporary Security Credentials for Mobile Apps Using Third-Party Identity
         * Providers</a>. </li> <li> <a
         * href="https://web-identity-federation-playground.s3.amazonaws.com/index.html">
         * Web Identity Federation Playground</a>. This interactive website lets you walk
         * through the process of authenticating via Login with Amazon, Facebook, or
         * Google, getting temporary security credentials, and then using those credentials
         * to make a request to AWS. </li> <li> <a
         * href="http://aws.amazon.com/sdkforios/">AWS SDK for iOS</a> and <a
         * href="http://aws.amazon.com/sdkforandroid/">AWS SDK for Android</a>. These
         * toolkits contain sample apps that show how to invoke the identity providers, and
         * then how to use the information from these providers to get and use temporary
         * security credentials. </li> <li> <a
         * href="http://aws.amazon.com/articles/4617974389850313">Web Identity Federation
         * with Mobile Applications</a>. This article discusses web identity federation and
         * shows an example of how to use web identity federation to get access to content
         * in Amazon S3. </li> </ul>
         */
        virtual Model::AssumeRoleWithWebIdentityOutcome AssumeRoleWithWebIdentity(const Model::AssumeRoleWithWebIdentityRequest& request) const;

        /**
         * <p>Returns a set of temporary security credentials for users who have been
         * authenticated in a mobile or web application with a web identity provider, such
         * as Amazon Cognito, Login with Amazon, Facebook, Google, or any OpenID
         * Connect-compatible identity provider. </p> <note> <p>For mobile applications, we
         * recommend that you use Amazon Cognito. You can use Amazon Cognito with the <a
         * href="http://aws.amazon.com/sdkforios/">AWS SDK for iOS</a> and the <a
         * href="http://aws.amazon.com/sdkforandroid/">AWS SDK for Android</a> to uniquely
         * identify a user and supply the user with a consistent identity throughout the
         * lifetime of an application.</p> <p>To learn more about Amazon Cognito, see <a
         * href="http://docs.aws.amazon.com/mobile/sdkforandroid/developerguide/cognito-auth.html#d0e840">Amazon
         * Cognito Overview</a> in the <i>AWS SDK for Android Developer Guide</i> guide and
         * <a
         * href="http://docs.aws.amazon.com/mobile/sdkforios/developerguide/cognito-auth.html#d0e664">Amazon
         * Cognito Overview</a> in the <i>AWS SDK for iOS Developer Guide</i>.</p> </note>
         * <p>Calling <code>AssumeRoleWithWebIdentity</code> does not require the use of
         * AWS security credentials. Therefore, you can distribute an application (for
         * example, on mobile devices) that requests temporary security credentials without
         * including long-term AWS credentials in the application, and without deploying
         * server-based proxy services that use long-term AWS credentials. Instead, the
         * identity of the caller is validated by using a token from the web identity
         * provider. </p> <p>The temporary security credentials returned by this API
         * consist of an access key ID, a secret access key, and a security token.
         * Applications can use these temporary security credentials to sign calls to AWS
         * service APIs. The credentials are valid for the duration that you specified when
         * calling <code>AssumeRoleWithWebIdentity</code>, which can be from 900 seconds
         * (15 minutes) to 3600 seconds (1 hour). By default, the temporary security
         * credentials are valid for 1 hour. </p> <p>Optionally, you can pass an IAM access
         * policy to this operation. If you choose not to pass a policy, the temporary
         * security credentials that are returned by the operation have the permissions
         * that are defined in the access policy of the role that is being assumed. If you
         * pass a policy to this operation, the temporary security credentials that are
         * returned by the operation have the permissions that are allowed by both the
         * access policy of the role that is being assumed, <i><b>and</b></i> the policy
         * that you pass. This gives you a way to further restrict the permissions for the
         * resulting temporary security credentials. You cannot use the passed policy to
         * grant permissions that are in excess of those allowed by the access policy of
         * the role that is being assumed. For more information, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/permissions-assume-role.html">Permissions
         * for AssumeRoleWithWebIdentity</a>.</p> <p>Before your application can call
         * <code>AssumeRoleWithWebIdentity</code>, you must have an identity token from a
         * supported identity provider and create a role that the application can assume.
         * The role that your application assumes must trust the identity provider that is
         * associated with the identity token. In other words, the identity provider must
         * be specified in the role's trust policy. </p> <p>For more information about how
         * to use web identity federation and the <code>AssumeRoleWithWebIdentity</code>
         * API, see the following resources: </p> <ul> <li> <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/STSUseCases.html#MobileApplication-KnownProvider">
         * Creating a Mobile Application with Third-Party Sign-In</a> and <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingWIF.html"> Creating
         * Temporary Security Credentials for Mobile Apps Using Third-Party Identity
         * Providers</a>. </li> <li> <a
         * href="https://web-identity-federation-playground.s3.amazonaws.com/index.html">
         * Web Identity Federation Playground</a>. This interactive website lets you walk
         * through the process of authenticating via Login with Amazon, Facebook, or
         * Google, getting temporary security credentials, and then using those credentials
         * to make a request to AWS. </li> <li> <a
         * href="http://aws.amazon.com/sdkforios/">AWS SDK for iOS</a> and <a
         * href="http://aws.amazon.com/sdkforandroid/">AWS SDK for Android</a>. These
         * toolkits contain sample apps that show how to invoke the identity providers, and
         * then how to use the information from these providers to get and use temporary
         * security credentials. </li> <li> <a
         * href="http://aws.amazon.com/articles/4617974389850313">Web Identity Federation
         * with Mobile Applications</a>. This article discusses web identity federation and
         * shows an example of how to use web identity federation to get access to content
         * in Amazon S3. </li> </ul>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::AssumeRoleWithWebIdentityOutcomeCallable AssumeRoleWithWebIdentityCallable(const Model::AssumeRoleWithWebIdentityRequest& request) const;

        /**
         * <p>Returns a set of temporary security credentials for users who have been
         * authenticated in a mobile or web application with a web identity provider, such
         * as Amazon Cognito, Login with Amazon, Facebook, Google, or any OpenID
         * Connect-compatible identity provider. </p> <note> <p>For mobile applications, we
         * recommend that you use Amazon Cognito. You can use Amazon Cognito with the <a
         * href="http://aws.amazon.com/sdkforios/">AWS SDK for iOS</a> and the <a
         * href="http://aws.amazon.com/sdkforandroid/">AWS SDK for Android</a> to uniquely
         * identify a user and supply the user with a consistent identity throughout the
         * lifetime of an application.</p> <p>To learn more about Amazon Cognito, see <a
         * href="http://docs.aws.amazon.com/mobile/sdkforandroid/developerguide/cognito-auth.html#d0e840">Amazon
         * Cognito Overview</a> in the <i>AWS SDK for Android Developer Guide</i> guide and
         * <a
         * href="http://docs.aws.amazon.com/mobile/sdkforios/developerguide/cognito-auth.html#d0e664">Amazon
         * Cognito Overview</a> in the <i>AWS SDK for iOS Developer Guide</i>.</p> </note>
         * <p>Calling <code>AssumeRoleWithWebIdentity</code> does not require the use of
         * AWS security credentials. Therefore, you can distribute an application (for
         * example, on mobile devices) that requests temporary security credentials without
         * including long-term AWS credentials in the application, and without deploying
         * server-based proxy services that use long-term AWS credentials. Instead, the
         * identity of the caller is validated by using a token from the web identity
         * provider. </p> <p>The temporary security credentials returned by this API
         * consist of an access key ID, a secret access key, and a security token.
         * Applications can use these temporary security credentials to sign calls to AWS
         * service APIs. The credentials are valid for the duration that you specified when
         * calling <code>AssumeRoleWithWebIdentity</code>, which can be from 900 seconds
         * (15 minutes) to 3600 seconds (1 hour). By default, the temporary security
         * credentials are valid for 1 hour. </p> <p>Optionally, you can pass an IAM access
         * policy to this operation. If you choose not to pass a policy, the temporary
         * security credentials that are returned by the operation have the permissions
         * that are defined in the access policy of the role that is being assumed. If you
         * pass a policy to this operation, the temporary security credentials that are
         * returned by the operation have the permissions that are allowed by both the
         * access policy of the role that is being assumed, <i><b>and</b></i> the policy
         * that you pass. This gives you a way to further restrict the permissions for the
         * resulting temporary security credentials. You cannot use the passed policy to
         * grant permissions that are in excess of those allowed by the access policy of
         * the role that is being assumed. For more information, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/permissions-assume-role.html">Permissions
         * for AssumeRoleWithWebIdentity</a>.</p> <p>Before your application can call
         * <code>AssumeRoleWithWebIdentity</code>, you must have an identity token from a
         * supported identity provider and create a role that the application can assume.
         * The role that your application assumes must trust the identity provider that is
         * associated with the identity token. In other words, the identity provider must
         * be specified in the role's trust policy. </p> <p>For more information about how
         * to use web identity federation and the <code>AssumeRoleWithWebIdentity</code>
         * API, see the following resources: </p> <ul> <li> <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/STSUseCases.html#MobileApplication-KnownProvider">
         * Creating a Mobile Application with Third-Party Sign-In</a> and <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingWIF.html"> Creating
         * Temporary Security Credentials for Mobile Apps Using Third-Party Identity
         * Providers</a>. </li> <li> <a
         * href="https://web-identity-federation-playground.s3.amazonaws.com/index.html">
         * Web Identity Federation Playground</a>. This interactive website lets you walk
         * through the process of authenticating via Login with Amazon, Facebook, or
         * Google, getting temporary security credentials, and then using those credentials
         * to make a request to AWS. </li> <li> <a
         * href="http://aws.amazon.com/sdkforios/">AWS SDK for iOS</a> and <a
         * href="http://aws.amazon.com/sdkforandroid/">AWS SDK for Android</a>. These
         * toolkits contain sample apps that show how to invoke the identity providers, and
         * then how to use the information from these providers to get and use temporary
         * security credentials. </li> <li> <a
         * href="http://aws.amazon.com/articles/4617974389850313">Web Identity Federation
         * with Mobile Applications</a>. This article discusses web identity federation and
         * shows an example of how to use web identity federation to get access to content
         * in Amazon S3. </li> </ul>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void AssumeRoleWithWebIdentityAsync(const Model::AssumeRoleWithWebIdentityRequest& request, const AssumeRoleWithWebIdentityResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Decodes additional information about the authorization status of a request
         * from an encoded message returned in response to an AWS request. </p> <p>For
         * example, if a user is not authorized to perform an action that he or she has
         * requested, the request returns a <code>Client.UnauthorizedOperation</code>
         * response (an HTTP 403 response). Some AWS actions additionally return an encoded
         * message that can provide details about this authorization failure. </p> <note>
         * Only certain AWS actions return an encoded authorization message. The
         * documentation for an individual action indicates whether that action returns an
         * encoded message in addition to returning an HTTP code. </note> <p>The message is
         * encoded because the details of the authorization status can constitute
         * privileged information that the user who requested the action should not see. To
         * decode an authorization status message, a user must be granted permissions via
         * an IAM policy to request the <code>DecodeAuthorizationMessage</code>
         * (<code>sts:DecodeAuthorizationMessage</code>) action. </p> <p>The decoded
         * message includes the following type of information: </p> <ul> <li>Whether the
         * request was denied due to an explicit deny or due to the absence of an explicit
         * allow. For more information, see <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/AccessPolicyLanguage_EvaluationLogic.html#policy-eval-denyallow">Determining
         * Whether a Request is Allowed or Denied</a> in <i>Using IAM</i>. </li> <li>The
         * principal who made the request.</li> <li>The requested action.</li> <li>The
         * requested resource.</li> <li>The values of condition keys in the context of the
         * user's request.</li> </ul>
         */
        virtual Model::DecodeAuthorizationMessageOutcome DecodeAuthorizationMessage(const Model::DecodeAuthorizationMessageRequest& request) const;

        /**
         * <p>Decodes additional information about the authorization status of a request
         * from an encoded message returned in response to an AWS request. </p> <p>For
         * example, if a user is not authorized to perform an action that he or she has
         * requested, the request returns a <code>Client.UnauthorizedOperation</code>
         * response (an HTTP 403 response). Some AWS actions additionally return an encoded
         * message that can provide details about this authorization failure. </p> <note>
         * Only certain AWS actions return an encoded authorization message. The
         * documentation for an individual action indicates whether that action returns an
         * encoded message in addition to returning an HTTP code. </note> <p>The message is
         * encoded because the details of the authorization status can constitute
         * privileged information that the user who requested the action should not see. To
         * decode an authorization status message, a user must be granted permissions via
         * an IAM policy to request the <code>DecodeAuthorizationMessage</code>
         * (<code>sts:DecodeAuthorizationMessage</code>) action. </p> <p>The decoded
         * message includes the following type of information: </p> <ul> <li>Whether the
         * request was denied due to an explicit deny or due to the absence of an explicit
         * allow. For more information, see <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/AccessPolicyLanguage_EvaluationLogic.html#policy-eval-denyallow">Determining
         * Whether a Request is Allowed or Denied</a> in <i>Using IAM</i>. </li> <li>The
         * principal who made the request.</li> <li>The requested action.</li> <li>The
         * requested resource.</li> <li>The values of condition keys in the context of the
         * user's request.</li> </ul>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DecodeAuthorizationMessageOutcomeCallable DecodeAuthorizationMessageCallable(const Model::DecodeAuthorizationMessageRequest& request) const;

        /**
         * <p>Decodes additional information about the authorization status of a request
         * from an encoded message returned in response to an AWS request. </p> <p>For
         * example, if a user is not authorized to perform an action that he or she has
         * requested, the request returns a <code>Client.UnauthorizedOperation</code>
         * response (an HTTP 403 response). Some AWS actions additionally return an encoded
         * message that can provide details about this authorization failure. </p> <note>
         * Only certain AWS actions return an encoded authorization message. The
         * documentation for an individual action indicates whether that action returns an
         * encoded message in addition to returning an HTTP code. </note> <p>The message is
         * encoded because the details of the authorization status can constitute
         * privileged information that the user who requested the action should not see. To
         * decode an authorization status message, a user must be granted permissions via
         * an IAM policy to request the <code>DecodeAuthorizationMessage</code>
         * (<code>sts:DecodeAuthorizationMessage</code>) action. </p> <p>The decoded
         * message includes the following type of information: </p> <ul> <li>Whether the
         * request was denied due to an explicit deny or due to the absence of an explicit
         * allow. For more information, see <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/AccessPolicyLanguage_EvaluationLogic.html#policy-eval-denyallow">Determining
         * Whether a Request is Allowed or Denied</a> in <i>Using IAM</i>. </li> <li>The
         * principal who made the request.</li> <li>The requested action.</li> <li>The
         * requested resource.</li> <li>The values of condition keys in the context of the
         * user's request.</li> </ul>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DecodeAuthorizationMessageAsync(const Model::DecodeAuthorizationMessageRequest& request, const DecodeAuthorizationMessageResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Returns a set of temporary security credentials (consisting of an access key
         * ID, a secret access key, and a security token) for a federated user. A typical
         * use is in a proxy application that gets temporary security credentials on behalf
         * of distributed applications inside a corporate network. Because you must call
         * the <code>GetFederationToken</code> action using the long-term security
         * credentials of an IAM user, this call is appropriate in contexts where those
         * credentials can be safely stored, usually in a server-based application.</p>
         * <note> <p> If you are creating a mobile-based or browser-based app that can
         * authenticate users using a web identity provider like Login with Amazon,
         * Facebook, Google, or an OpenID Connect-compatible identity provider, we
         * recommend that you use <a href="http://aws.amazon.com/cognito/">Amazon
         * Cognito</a> or <code>AssumeRoleWithWebIdentity</code>. For more information, see
         * <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingWIF.html">Creating
         * Temporary Security Credentials for Mobile Apps Using Identity Providers</a>.</p>
         * </note> <p>The <code>GetFederationToken</code> action must be called by using
         * the long-term AWS security credentials of an IAM user. You can also call
         * <code>GetFederationToken</code> using the security credentials of an AWS account
         * (root), but this is not recommended. Instead, we recommend that you create an
         * IAM user for the purpose of the proxy application and then attach a policy to
         * the IAM user that limits federated users to only the actions and resources they
         * need access to. For more information, see <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/IAMBestPractices.html">IAM
         * Best Practices</a> in <i>Using IAM</i>. </p> <p>The temporary security
         * credentials that are obtained by using the long-term credentials of an IAM user
         * are valid for the specified duration, between 900 seconds (15 minutes) and
         * 129600 seconds (36 hours). Temporary credentials that are obtained by using AWS
         * account (root) credentials have a maximum duration of 3600 seconds (1 hour)</p>
         * <p> <b>Permissions</b> </p> <p>The permissions for the temporary security
         * credentials returned by <code>GetFederationToken</code> are determined by a
         * combination of the following: </p> <ul> <li>The policy or policies that are
         * attached to the IAM user whose credentials are used to call
         * <code>GetFederationToken</code>.</li> <li>The policy that is passed as a
         * parameter in the call.</li> </ul> <p>The passed policy is attached to the
         * temporary security credentials that result from the
         * <code>GetFederationToken</code> API call--that is, to the <i>federated user</i>.
         * When the federated user makes an AWS request, AWS evaluates the policy attached
         * to the federated user in combination with the policy or policies attached to the
         * IAM user whose credentials were used to call <code>GetFederationToken</code>.
         * AWS allows the federated user's request only when both the federated user
         * <i><b>and</b></i> the IAM user are explicitly allowed to perform the requested
         * action. The passed policy cannot grant more permissions than those that are
         * defined in the IAM user policy.</p> <p>A typical use case is that the
         * permissions of the IAM user whose credentials are used to call
         * <code>GetFederationToken</code> are designed to allow access to all the actions
         * and resources that any federated user will need. Then, for individual users, you
         * pass a policy to the operation that scopes down the permissions to a level
         * that's appropriate to that individual user, using a policy that allows only a
         * subset of permissions that are granted to the IAM user. </p> <p>If you do not
         * pass a policy, the resulting temporary security credentials have no effective
         * permissions. The only exception is when the temporary security credentials are
         * used to access a resource that has a resource-based policy that specifically
         * allows the federated user to access the resource. </p> <p>For more information
         * about how permissions work, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/permissions-get-federation-token.html">Permissions
         * for GetFederationToken</a>. For information about using
         * <code>GetFederationToken</code> to create temporary security credentials, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingFedTokens.html">Creating
         * Temporary Credentials to Enable Access for Federated Users</a>. </p>
         */
        virtual Model::GetFederationTokenOutcome GetFederationToken(const Model::GetFederationTokenRequest& request) const;

        /**
         * <p>Returns a set of temporary security credentials (consisting of an access key
         * ID, a secret access key, and a security token) for a federated user. A typical
         * use is in a proxy application that gets temporary security credentials on behalf
         * of distributed applications inside a corporate network. Because you must call
         * the <code>GetFederationToken</code> action using the long-term security
         * credentials of an IAM user, this call is appropriate in contexts where those
         * credentials can be safely stored, usually in a server-based application.</p>
         * <note> <p> If you are creating a mobile-based or browser-based app that can
         * authenticate users using a web identity provider like Login with Amazon,
         * Facebook, Google, or an OpenID Connect-compatible identity provider, we
         * recommend that you use <a href="http://aws.amazon.com/cognito/">Amazon
         * Cognito</a> or <code>AssumeRoleWithWebIdentity</code>. For more information, see
         * <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingWIF.html">Creating
         * Temporary Security Credentials for Mobile Apps Using Identity Providers</a>.</p>
         * </note> <p>The <code>GetFederationToken</code> action must be called by using
         * the long-term AWS security credentials of an IAM user. You can also call
         * <code>GetFederationToken</code> using the security credentials of an AWS account
         * (root), but this is not recommended. Instead, we recommend that you create an
         * IAM user for the purpose of the proxy application and then attach a policy to
         * the IAM user that limits federated users to only the actions and resources they
         * need access to. For more information, see <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/IAMBestPractices.html">IAM
         * Best Practices</a> in <i>Using IAM</i>. </p> <p>The temporary security
         * credentials that are obtained by using the long-term credentials of an IAM user
         * are valid for the specified duration, between 900 seconds (15 minutes) and
         * 129600 seconds (36 hours). Temporary credentials that are obtained by using AWS
         * account (root) credentials have a maximum duration of 3600 seconds (1 hour)</p>
         * <p> <b>Permissions</b> </p> <p>The permissions for the temporary security
         * credentials returned by <code>GetFederationToken</code> are determined by a
         * combination of the following: </p> <ul> <li>The policy or policies that are
         * attached to the IAM user whose credentials are used to call
         * <code>GetFederationToken</code>.</li> <li>The policy that is passed as a
         * parameter in the call.</li> </ul> <p>The passed policy is attached to the
         * temporary security credentials that result from the
         * <code>GetFederationToken</code> API call--that is, to the <i>federated user</i>.
         * When the federated user makes an AWS request, AWS evaluates the policy attached
         * to the federated user in combination with the policy or policies attached to the
         * IAM user whose credentials were used to call <code>GetFederationToken</code>.
         * AWS allows the federated user's request only when both the federated user
         * <i><b>and</b></i> the IAM user are explicitly allowed to perform the requested
         * action. The passed policy cannot grant more permissions than those that are
         * defined in the IAM user policy.</p> <p>A typical use case is that the
         * permissions of the IAM user whose credentials are used to call
         * <code>GetFederationToken</code> are designed to allow access to all the actions
         * and resources that any federated user will need. Then, for individual users, you
         * pass a policy to the operation that scopes down the permissions to a level
         * that's appropriate to that individual user, using a policy that allows only a
         * subset of permissions that are granted to the IAM user. </p> <p>If you do not
         * pass a policy, the resulting temporary security credentials have no effective
         * permissions. The only exception is when the temporary security credentials are
         * used to access a resource that has a resource-based policy that specifically
         * allows the federated user to access the resource. </p> <p>For more information
         * about how permissions work, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/permissions-get-federation-token.html">Permissions
         * for GetFederationToken</a>. For information about using
         * <code>GetFederationToken</code> to create temporary security credentials, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingFedTokens.html">Creating
         * Temporary Credentials to Enable Access for Federated Users</a>. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::GetFederationTokenOutcomeCallable GetFederationTokenCallable(const Model::GetFederationTokenRequest& request) const;

        /**
         * <p>Returns a set of temporary security credentials (consisting of an access key
         * ID, a secret access key, and a security token) for a federated user. A typical
         * use is in a proxy application that gets temporary security credentials on behalf
         * of distributed applications inside a corporate network. Because you must call
         * the <code>GetFederationToken</code> action using the long-term security
         * credentials of an IAM user, this call is appropriate in contexts where those
         * credentials can be safely stored, usually in a server-based application.</p>
         * <note> <p> If you are creating a mobile-based or browser-based app that can
         * authenticate users using a web identity provider like Login with Amazon,
         * Facebook, Google, or an OpenID Connect-compatible identity provider, we
         * recommend that you use <a href="http://aws.amazon.com/cognito/">Amazon
         * Cognito</a> or <code>AssumeRoleWithWebIdentity</code>. For more information, see
         * <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingWIF.html">Creating
         * Temporary Security Credentials for Mobile Apps Using Identity Providers</a>.</p>
         * </note> <p>The <code>GetFederationToken</code> action must be called by using
         * the long-term AWS security credentials of an IAM user. You can also call
         * <code>GetFederationToken</code> using the security credentials of an AWS account
         * (root), but this is not recommended. Instead, we recommend that you create an
         * IAM user for the purpose of the proxy application and then attach a policy to
         * the IAM user that limits federated users to only the actions and resources they
         * need access to. For more information, see <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/IAMBestPractices.html">IAM
         * Best Practices</a> in <i>Using IAM</i>. </p> <p>The temporary security
         * credentials that are obtained by using the long-term credentials of an IAM user
         * are valid for the specified duration, between 900 seconds (15 minutes) and
         * 129600 seconds (36 hours). Temporary credentials that are obtained by using AWS
         * account (root) credentials have a maximum duration of 3600 seconds (1 hour)</p>
         * <p> <b>Permissions</b> </p> <p>The permissions for the temporary security
         * credentials returned by <code>GetFederationToken</code> are determined by a
         * combination of the following: </p> <ul> <li>The policy or policies that are
         * attached to the IAM user whose credentials are used to call
         * <code>GetFederationToken</code>.</li> <li>The policy that is passed as a
         * parameter in the call.</li> </ul> <p>The passed policy is attached to the
         * temporary security credentials that result from the
         * <code>GetFederationToken</code> API call--that is, to the <i>federated user</i>.
         * When the federated user makes an AWS request, AWS evaluates the policy attached
         * to the federated user in combination with the policy or policies attached to the
         * IAM user whose credentials were used to call <code>GetFederationToken</code>.
         * AWS allows the federated user's request only when both the federated user
         * <i><b>and</b></i> the IAM user are explicitly allowed to perform the requested
         * action. The passed policy cannot grant more permissions than those that are
         * defined in the IAM user policy.</p> <p>A typical use case is that the
         * permissions of the IAM user whose credentials are used to call
         * <code>GetFederationToken</code> are designed to allow access to all the actions
         * and resources that any federated user will need. Then, for individual users, you
         * pass a policy to the operation that scopes down the permissions to a level
         * that's appropriate to that individual user, using a policy that allows only a
         * subset of permissions that are granted to the IAM user. </p> <p>If you do not
         * pass a policy, the resulting temporary security credentials have no effective
         * permissions. The only exception is when the temporary security credentials are
         * used to access a resource that has a resource-based policy that specifically
         * allows the federated user to access the resource. </p> <p>For more information
         * about how permissions work, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/permissions-get-federation-token.html">Permissions
         * for GetFederationToken</a>. For information about using
         * <code>GetFederationToken</code> to create temporary security credentials, see <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingFedTokens.html">Creating
         * Temporary Credentials to Enable Access for Federated Users</a>. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void GetFederationTokenAsync(const Model::GetFederationTokenRequest& request, const GetFederationTokenResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Returns a set of temporary credentials for an AWS account or IAM user. The
         * credentials consist of an access key ID, a secret access key, and a security
         * token. Typically, you use <code>GetSessionToken</code> if you want to use MFA to
         * protect programmatic calls to specific AWS APIs like Amazon EC2
         * <code>StopInstances</code>. MFA-enabled IAM users would need to call
         * <code>GetSessionToken</code> and submit an MFA code that is associated with
         * their MFA device. Using the temporary security credentials that are returned
         * from the call, IAM users can then make programmatic calls to APIs that require
         * MFA authentication. </p> <p>The <code>GetSessionToken</code> action must be
         * called by using the long-term AWS security credentials of the AWS account or an
         * IAM user. Credentials that are created by IAM users are valid for the duration
         * that you specify, between 900 seconds (15 minutes) and 129600 seconds (36
         * hours); credentials that are created by using account credentials have a maximum
         * duration of 3600 seconds (1 hour). </p> <note> <p>We recommend that you do not
         * call <code>GetSessionToken</code> with root account credentials. Instead, follow
         * our <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/IAMBestPractices.html#create-iam-users">best
         * practices</a> by creating one or more IAM users, giving them the necessary
         * permissions, and using IAM users for everyday interaction with AWS. </p> </note>
         * <p>The permissions associated with the temporary security credentials returned
         * by <code>GetSessionToken</code> are based on the permissions associated with
         * account or IAM user whose credentials are used to call the action. If
         * <code>GetSessionToken</code> is called using root account credentials, the
         * temporary credentials have root account permissions. Similarly, if
         * <code>GetSessionToken</code> is called using the credentials of an IAM user, the
         * temporary credentials have the same permissions as the IAM user. </p> <p>For
         * more information about using <code>GetSessionToken</code> to create temporary
         * credentials, go to <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingSessionTokens.html"
         * target="_blank">Creating Temporary Credentials to Enable Access for IAM
         * Users</a>. </p>
         */
        virtual Model::GetSessionTokenOutcome GetSessionToken(const Model::GetSessionTokenRequest& request) const;

        /**
         * <p>Returns a set of temporary credentials for an AWS account or IAM user. The
         * credentials consist of an access key ID, a secret access key, and a security
         * token. Typically, you use <code>GetSessionToken</code> if you want to use MFA to
         * protect programmatic calls to specific AWS APIs like Amazon EC2
         * <code>StopInstances</code>. MFA-enabled IAM users would need to call
         * <code>GetSessionToken</code> and submit an MFA code that is associated with
         * their MFA device. Using the temporary security credentials that are returned
         * from the call, IAM users can then make programmatic calls to APIs that require
         * MFA authentication. </p> <p>The <code>GetSessionToken</code> action must be
         * called by using the long-term AWS security credentials of the AWS account or an
         * IAM user. Credentials that are created by IAM users are valid for the duration
         * that you specify, between 900 seconds (15 minutes) and 129600 seconds (36
         * hours); credentials that are created by using account credentials have a maximum
         * duration of 3600 seconds (1 hour). </p> <note> <p>We recommend that you do not
         * call <code>GetSessionToken</code> with root account credentials. Instead, follow
         * our <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/IAMBestPractices.html#create-iam-users">best
         * practices</a> by creating one or more IAM users, giving them the necessary
         * permissions, and using IAM users for everyday interaction with AWS. </p> </note>
         * <p>The permissions associated with the temporary security credentials returned
         * by <code>GetSessionToken</code> are based on the permissions associated with
         * account or IAM user whose credentials are used to call the action. If
         * <code>GetSessionToken</code> is called using root account credentials, the
         * temporary credentials have root account permissions. Similarly, if
         * <code>GetSessionToken</code> is called using the credentials of an IAM user, the
         * temporary credentials have the same permissions as the IAM user. </p> <p>For
         * more information about using <code>GetSessionToken</code> to create temporary
         * credentials, go to <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingSessionTokens.html"
         * target="_blank">Creating Temporary Credentials to Enable Access for IAM
         * Users</a>. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::GetSessionTokenOutcomeCallable GetSessionTokenCallable(const Model::GetSessionTokenRequest& request) const;

        /**
         * <p>Returns a set of temporary credentials for an AWS account or IAM user. The
         * credentials consist of an access key ID, a secret access key, and a security
         * token. Typically, you use <code>GetSessionToken</code> if you want to use MFA to
         * protect programmatic calls to specific AWS APIs like Amazon EC2
         * <code>StopInstances</code>. MFA-enabled IAM users would need to call
         * <code>GetSessionToken</code> and submit an MFA code that is associated with
         * their MFA device. Using the temporary security credentials that are returned
         * from the call, IAM users can then make programmatic calls to APIs that require
         * MFA authentication. </p> <p>The <code>GetSessionToken</code> action must be
         * called by using the long-term AWS security credentials of the AWS account or an
         * IAM user. Credentials that are created by IAM users are valid for the duration
         * that you specify, between 900 seconds (15 minutes) and 129600 seconds (36
         * hours); credentials that are created by using account credentials have a maximum
         * duration of 3600 seconds (1 hour). </p> <note> <p>We recommend that you do not
         * call <code>GetSessionToken</code> with root account credentials. Instead, follow
         * our <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/IAMBestPractices.html#create-iam-users">best
         * practices</a> by creating one or more IAM users, giving them the necessary
         * permissions, and using IAM users for everyday interaction with AWS. </p> </note>
         * <p>The permissions associated with the temporary security credentials returned
         * by <code>GetSessionToken</code> are based on the permissions associated with
         * account or IAM user whose credentials are used to call the action. If
         * <code>GetSessionToken</code> is called using root account credentials, the
         * temporary credentials have root account permissions. Similarly, if
         * <code>GetSessionToken</code> is called using the credentials of an IAM user, the
         * temporary credentials have the same permissions as the IAM user. </p> <p>For
         * more information about using <code>GetSessionToken</code> to create temporary
         * credentials, go to <a
         * href="http://docs.aws.amazon.com/STS/latest/UsingSTS/CreatingSessionTokens.html"
         * target="_blank">Creating Temporary Credentials to Enable Access for IAM
         * Users</a>. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void GetSessionTokenAsync(const Model::GetSessionTokenRequest& request, const GetSessionTokenResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;


  private:
    void init(const Client::ClientConfiguration& clientConfiguration);

        /**Async helpers**/
        void AssumeRoleAsyncHelper(const Model::AssumeRoleRequest& request, const AssumeRoleResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void AssumeRoleWithSAMLAsyncHelper(const Model::AssumeRoleWithSAMLRequest& request, const AssumeRoleWithSAMLResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void AssumeRoleWithWebIdentityAsyncHelper(const Model::AssumeRoleWithWebIdentityRequest& request, const AssumeRoleWithWebIdentityResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DecodeAuthorizationMessageAsyncHelper(const Model::DecodeAuthorizationMessageRequest& request, const DecodeAuthorizationMessageResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void GetFederationTokenAsyncHelper(const Model::GetFederationTokenRequest& request, const GetFederationTokenResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void GetSessionTokenAsyncHelper(const Model::GetSessionTokenRequest& request, const GetSessionTokenResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;

    Aws::String m_uri;
    std::shared_ptr<Utils::Threading::Executor> m_executor;
  };

} // namespace STS
} // namespace Aws