// Copyright 2023 Metaseven. All Rights Reserved.

#include "AutoFootstepEffectContext.h"
#include "Engine/AssetManager.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "Sound/SoundBase.h"

void UAutoFootstepEffectContext::SpawnEffectBySurfaceType(const UObject* WorldContextObject, const TEnumAsByte<EPhysicalSurface> SurfaceType, const FVector& Location, const FRotator& Rotation, const FAutoFootstepNiagaraParams& NiagaraParams, const FAutoFootstepSoundParams& SoundParams)
{
	if (const FAutoFootstepEffect* Effect = EffectsForSurface.Find(SurfaceType))
	{
		TArray<FSoftObjectPath> EffectPaths;

		if (!Effect->Niagara.IsValid() && !Effect->Niagara.IsNull())
		{
			EffectPaths.Emplace(Effect->Niagara.ToSoftObjectPath());
		}

		if (!Effect->Sound.IsValid() && !Effect->Sound.IsNull())
		{
			EffectPaths.Emplace(Effect->Sound.ToSoftObjectPath());
		}

		if (EffectPaths.IsEmpty())
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(WorldContextObject, Effect->Niagara.Get(), Location + NiagaraParams.LocationOffset, Rotation + NiagaraParams.RotationOffset, NiagaraParams.Scale, true, true, NiagaraParams.PoolingMethod);
			UGameplayStatics::PlaySoundAtLocation(WorldContextObject, Effect->Sound.Get(), Location + SoundParams.LocationOffset, Rotation + SoundParams.RotationOffset, SoundParams.VolumeMultiplier, SoundParams.PitchMultiplier);
		}
		else
		{
			UAssetManager::GetStreamableManager().RequestAsyncLoad(EffectPaths, [WorldContextObject, Effect, Location, Rotation, NiagaraParams, SoundParams]()
			{
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(WorldContextObject, Effect->Niagara.Get(), Location + NiagaraParams.LocationOffset, Rotation + NiagaraParams.RotationOffset, NiagaraParams.Scale, true, true, NiagaraParams.PoolingMethod);
				UGameplayStatics::PlaySoundAtLocation(WorldContextObject, Effect->Sound.Get(), Location + SoundParams.LocationOffset, Rotation + SoundParams.RotationOffset, SoundParams.VolumeMultiplier, SoundParams.PitchMultiplier);
			});
		}
	}
}
