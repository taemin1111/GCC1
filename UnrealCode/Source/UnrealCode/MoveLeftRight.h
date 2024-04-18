// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveLeftRight.generated.h" //Unreal Class ���̺귯�� ���� �������� generated include �ʼ� (������ include �Ұ�) 

UCLASS() // Unreal Ŭ���� �ɼ� �Է�
class UNREALCODE_API/*��� API �̸�*/ AMoveLeftRight : public AActor
{
	GENERATED_BODY() //Unreal �ڵ� ���� ó��
	
public:	
	// Sets default values for this actor's properties
	AMoveLeftRight(); //Ŭ������ �����ɶ� ����

protected://��Ӱ��踸 ���ٰ���
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
