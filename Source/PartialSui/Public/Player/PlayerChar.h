// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerChar.generated.h"


class USpringArmComponent;

UCLASS()
class PARTIALSUI_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChar();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Functions

	UFUNCTION(BlueprintNativeEvent)
		void JumpIt();
	void JumpIt_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void JumpItStop();
	void JumpItStop_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void Attack();
	void Attack_Implementation();
	
	UFUNCTION(BlueprintNativeEvent)
		void AttackStop();
	void AttackStop_Implementation();
	
	UFUNCTION(BlueprintNativeEvent)
		void Dodge();
	void Dodge_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void DodgeStop();
	void DodgeStop_Implementation();
	
	UFUNCTION(BlueprintNativeEvent)
		void Up();
	void Up_Implementation();
	
	UFUNCTION(BlueprintNativeEvent)
		void UpStop();
	void UpStop_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void Down();
	void Down_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void DownStop();
	void DownStop_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void Sprint();
	void Sprint_Implementation();

	
	UFUNCTION(BlueprintNativeEvent)
		void SprintStop();
	void SprintStop_Implementation();

	void MoveRight(float Value);

	UFUNCTION(BlueprintCallable)
		FHitResult ForwardTrace(FVector Start, float TraceMulti);

	//Variabls

	UPROPERTY(EditAnywhere, Category = "Tracing")
		float WallTraceDistance;

	UPROPERTY(EditAnywhere, Category = "Tracing")
		float HitTraceDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle")
		bool Attacking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle")
		int CountAttacks;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle")
		bool Dodging;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle")
		FRotator DesiredRotation;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
