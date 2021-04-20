// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerChar.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "DrawDebugHelpers.h"

#define Collision_PlayerHit ECC_GameTraceChannel2
#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Emerald, String)

// Sets default values
APlayerChar::APlayerChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	WallTraceDistance = 200.0f;
	HitTraceDistance = 200.0f;
	Attacking = false;
	CountAttacks = 0;
	Dodging = false;
	DesiredRotation = FRotator(0.0f, -90.0f, 0.0f);
	AttackThreshold = 600;

	AttackPlayRate = 1;
	LastAttack = false;

	EnumPlayerState = EPlayerState::Stand;

}

// Called when the game starts or when spawned
void APlayerChar::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerChar::AttackParameters(UAnimMontage* MontageToPlay, float PlayRate, bool Last, FName Socket)
{
	AttackMontage = MontageToPlay;
	LastAttack = Last;
	AttackPlayRate = PlayRate;
	TraceSocket = Socket;
}

void APlayerChar::AttackFunction()
{
	if (EnumPlayerState != EPlayerState::Att)
	{
		EnumPlayerState = EPlayerState::Att;
		/*switch (CountAttacks)
		{
		case 0:

		case 1:

		case 2:

		}*/
	}
}

void APlayerChar::JumpIt_Implementation()
{
}

void APlayerChar::JumpItStop_Implementation()
{
}

void APlayerChar::Attack_Implementation()
{	
	
	
	
}

void APlayerChar::AttackStop_Implementation()
{
}

void APlayerChar::Dodge_Implementation()
{
}

void APlayerChar::DodgeStop_Implementation()
{
}

void APlayerChar::Up_Implementation()
{
}

void APlayerChar::UpStop_Implementation()
{
}

void APlayerChar::Down_Implementation()
{
}


void APlayerChar::DownStop_Implementation()
{
}

void APlayerChar::Sprint_Implementation()
{
}

void APlayerChar::SprintStop_Implementation()
{
}

void APlayerChar::MoveRight(float Value)
{
	if ((Controller) && (Value != 0.0f) && (Attacking == false) && (Dodging == false))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		//FMath::Lerp(1, 2, 0.5);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		DesiredRotation = FRotator(0, Value * 90, 0);
		const FQuat QuatRotation = FQuat(DesiredRotation);
		SetActorRotation(QuatRotation, ETeleportType::None);
		AddMovementInput(Direction, Value);
	}
}

FHitResult APlayerChar::ForwardTrace(FVector Start, float TraceMulti)
{

	FHitResult Hit;

	FVector ForwardVec = GetActorForwardVector();
	FVector End = Start + ForwardVec * TraceMulti;

	FCollisionQueryParams TraceParams(FName(TEXT("Trace")), false, this);

	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, Collision_PlayerHit, TraceParams);
	
	DrawDebugLine(GetWorld(), Start, End, FColor::Orange, false, 1.0f);
	
	if (Hit.bBlockingHit)
	{
		DrawDebugBox(GetWorld(), Hit.ImpactPoint, FVector(5, 5, 5), FColor::Magenta, false, 1.0f);
	}
	
	return Hit;
}

// Called every frame
void APlayerChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



// Called to bind functionality to input
void APlayerChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerChar::JumpIt);
	PlayerInputComponent->BindAction("Jump", IE_Released , this, &APlayerChar::JumpItStop);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &APlayerChar::Attack);
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &APlayerChar::AttackStop);

	PlayerInputComponent->BindAction("Dodge", IE_Pressed, this, &APlayerChar::Dodge);
	PlayerInputComponent->BindAction("Dodge", IE_Released, this, &APlayerChar::DodgeStop);

	PlayerInputComponent->BindAction("Up", IE_Pressed, this, &APlayerChar::Up);
	PlayerInputComponent->BindAction("Up", IE_Released, this, &APlayerChar::UpStop);
	
	PlayerInputComponent->BindAction("Down", IE_Pressed, this, &APlayerChar::Down);
	PlayerInputComponent->BindAction("Down", IE_Released, this, &APlayerChar::DownStop);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &APlayerChar::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &APlayerChar::SprintStop);


	PlayerInputComponent->BindAxis("RightLeft", this, &APlayerChar::MoveRight);
	//PlayerInputComponent->BindAxis("LookUpDown", this, &APlayerChar::LookUp);
	//PlayerInputComponent->BindAxis("LookRightLeft", this, &APlayerChar::LookRight);






}


