#pragma once

#include "OscDataElemStruct.h"
#include "OscMessageStruct.generated.h"


USTRUCT(BlueprintType)
struct UE4_OSC_API FOscMessageStruct
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Address;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FOscDataElemStruct> Data;
};
