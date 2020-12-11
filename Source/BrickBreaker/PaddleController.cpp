// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddleController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Paddle.h"
#include "Ball.h"

APaddleController::APaddleController()
{
}

void APaddleController::BeginPlay()
{
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

	SpawnNewBall();
}

void APaddleController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	EnableInput(this);

	InputComponent->BindAxis("MoveHorizontal", this, &APaddleController::MoveHorizontal);
	InputComponent->BindAction("Launch", IE_Pressed, this, &APaddleController::Launch);
}

void APaddleController::MoveHorizontal(float AxisValue)
{
	auto MyPawn = Cast<APaddle>(GetPawn());
	if (MyPawn)
	{
		MyPawn->MoveHorizontal(AxisValue);
	}
}

void APaddleController::Launch()
{
	MyBall->Launch();
}

void APaddleController::SpawnNewBall()
{
	if (!MyBall)
	{
		MyBall = nullptr;
	}

	if (BallObj)
	{
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotation, SpawnInfo);
	}
}
