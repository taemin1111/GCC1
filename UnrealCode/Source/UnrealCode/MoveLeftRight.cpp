// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"

// Sets default values
AMoveLeftRight::AMoveLeftRight():IsMoveRight(true), LocX(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Scene : 생성해서 넣을 변수
	// = : 대입 연산자(오른쪽에 있는걸 왼쪽에 넣는다.)
	// CreateDefaultSubobject : 생성 도구
	// USceneComponent : 생성할 클래스 지정
	// TEXT("Scene") : 블루프린트에서 보여질 이름
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	SetRootComponent(Scene); // Scene을 Root Component로 만든다.
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform); // StaticMesh를 상대 좌표계 기준으로 Scene에 붙인다.
	StaticMesh->SetRelativeTransform(FTransform::Identity); // StaticMesh의 RelativeTransform(고유위치)을 기본값으로 설정한다.
}

// Called when the game starts or when spawned
void AMoveLeftRight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveLeftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsMoveRight)
	{
		//True
		LocX = LocX + 1; // LocX += 1;
		StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));
		FVector location = StaticMesh->GetRelativeLocation();
		if (location.X > 200) 
		{
			IsMoveRight = false;
		}
	}
	else
	{
		//False
		LocX = LocX - 1; // LocX -= 1;
		StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));
		FVector location = StaticMesh->GetRelativeLocation();
		if (location.X < 0)
		{
			IsMoveRight = true;
		}
	}
}

