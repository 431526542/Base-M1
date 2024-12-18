// Copyright 2022, ALT LLC. All Rights Reserved.
// This file is part of Antilatency SDK.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://www.antilatency.com/eula
// You may not use this file except in compliance with the License.
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "PhysicalConfigurableEnvironmentLibrary.h"

#include "PhysicalConfigurableEnvironmentLog.h"

#include <ObjectConstructor.h>
#include <ExceptionCheck.h>

#include "IAntilatencyPhysicalConfigurableEnvironmentModule.h"

UPhysicalConfigurableEnvironmentLibrary* UPhysicalConfigurableEnvironmentLibrary::GetLibrary() {
    auto module = IAntilatencyPhysicalConfigurableEnvironmentModule::Get();
    auto native = module.GetNativeLibrary();

    if (native == nullptr) {
        return nullptr;
    }

    return ObjectConstructor<UPhysicalConfigurableEnvironmentLibrary>::create(native);
}

UPhysicalConfigurableEnvironmentLibrary::TInterface UPhysicalConfigurableEnvironmentLibrary::GetNative() {
    return _native;
}

Antilatency::InterfaceContract::ExceptionCode UPhysicalConfigurableEnvironmentLibrary::CreateCotaskConstructor(UPhysicalConfigurableEnvironmentCotaskConstructor*& result) {
    if (!IsValid()) {
        PHYSICALCONFIGURABLEENVRIONMENT_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
        return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
    }

    Antilatency::PhysicalConfigurableEnvironment::ICotaskConstructor nativeResult;
    auto exception = _native.createCotaskConstructor(nativeResult);
    ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = ObjectConstructor<UPhysicalConfigurableEnvironmentCotaskConstructor>::create(nativeResult);
    return exception;
}

bool UPhysicalConfigurableEnvironmentLibrary::IsValid() const {
    return _native != nullptr;
}


