// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HEXR_TEST_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	UFUNCTION(BlueprintCallable)
	void RightRotation(float value);

	UFUNCTION(BlueprintCallable)
		void LeftRotation(float value);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	


private:
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* RotateMesh;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* Guitar;

	UPROPERTY(VisibleAnywhere)
		class USceneComponent* Effect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
		class UParticleSystem* ParticleEffect;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		float LeftRotationRate = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		float RightRotationRate = 0.0f;
};
