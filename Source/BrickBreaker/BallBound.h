// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallBound.generated.h"

class UBoxComponent;
class APaddleController;

UCLASS()
class BRICKBREAKER_API ABallBound : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallBound();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* BoxCollision;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFroSweep,
			const FHitResult& SweepResult);

	APaddleController* PaddleControllerREF;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
