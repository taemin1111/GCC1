// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveLeftRight.generated.h" //Unreal Class 라이브러리 생성 마지막에 generated include 필수 (다음에 include 불가) 

UCLASS() // Unreal 클래스 옵션 입력
class UNREALCODE_API/*모듈 API 이름*/ AMoveLeftRight : public AActor
{
	GENERATED_BODY() //Unreal 코드 생성 처리
	
public:	
	// Sets default values for this actor's properties
	AMoveLeftRight(); //클래스가 생성될때 실행

protected://상속관계만 접근가능
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	USceneComponent* Scene;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(BlueprintReadOnly)
	bool IsMoveRight;

	float LocX;
};
