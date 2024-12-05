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

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "AltEnvironment.h"

#include <ObjectConstructor.h>
#include <Antilatency.Alt.Environment.h>

#include "EnvironmentConstructor.generated.h"

/**
 * Antilatency::Alt::Environment::IEnvironmentConstructor wrapper for UE.
 * Do not instantiate this class by calling NewObject<UEnvironmentConstructor> method.
 */
UCLASS(BlueprintType)
class ANTILATENCYALTTRACKING_API UEnvironmentConstructor : public UObject {
    GENERATED_BODY()

public:
    typedef Antilatency::Alt::Environment::IEnvironmentConstructor TInterface;
    
    template<class TInterfacedObject>
    friend class ObjectConstructor;
    
    TInterface GetNative();
    bool IsValid() const;

    Antilatency::InterfaceContract::ExceptionCode CreateEnvironment(const FString& data, UAltEnvironment*& result);


protected:
    template<class TSpecificInterface>
    TSpecificInterface& AsInterface() {
        return *static_cast<TSpecificInterface*>(&_native);
    }

    /** A pointer to the native object. */
    TInterface _native;
};