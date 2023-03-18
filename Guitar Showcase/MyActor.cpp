// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RotateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RotateMesh"));
	RotateMesh->SetupAttachment(GetRootComponent());

	Guitar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Guitar"));
	Guitar->SetupAttachment(RotateMesh);

	Effect = CreateDefaultSubobject<USceneComponent>(TEXT("Effect"));
	Effect->SetupAttachment(RotateMesh);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleEffect, Effect->GetComponentLocation());

}
void AMyActor::RightRotation(float value)
{

	FRotator CurrentRotation = FRotator::ZeroRotator;
	CurrentRotation.Yaw = value * RightRotationRate * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(CurrentRotation, true);

	

}

void AMyActor::LeftRotation(float value)
{
	FRotator CurrentRotation = FRotator::ZeroRotator;
	CurrentRotation.Yaw = value * LeftRotationRate * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(CurrentRotation, true);

	
}
