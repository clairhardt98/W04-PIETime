#include "PointLightComponent.h"
#include "UObject/ObjectFactory.h"
#include "CoreUObject/UObject/Casts.h"

UPointLightComponent::UPointLightComponent()
{
}

UPointLightComponent::UPointLightComponent(const UPointLightComponent& Other)
{
}

UObject* UPointLightComponent::Duplicate() const
{
    UPointLightComponent* NewComp = FObjectFactory::ConstructObjectFrom<UPointLightComponent>(this);
    NewComp->DuplicateSubObjects(this);
    NewComp->PostDuplicate();

    return NewComp;
}

void UPointLightComponent::DuplicateSubObjects(const UObject* Source)
{
    Super::DuplicateSubObjects(Source);
    // 여기서 복사할 것? 반경뿐임
    UPointLightComponent* SourceComp = Cast<UPointLightComponent>(Source);
    if (SourceComp)
    {
        Radius = SourceComp->Radius;
    }
}

void UPointLightComponent::PostDuplicate()
{
}
