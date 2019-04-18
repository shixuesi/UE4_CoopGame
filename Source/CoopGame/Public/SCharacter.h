// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ASWeapon;
UCLASS()
class COOPGAME_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();
	virtual FVector GetPawnViewLocation()  const override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);
	void MoveRight(float value);

	void BeginCrouch();
	void EndCrouch();

	void BeginZoom();
	void EndZoom();

	//void Fire();

	void SwitchWeapons(FKey Key);

	void GenWeapon(TSubclassOf<ASWeapon>& Weapon);
	

	UPROPERTY(EditDefaultsOnly,Category = "WeaponsSetting")
	TSubclassOf<ASWeapon> Weapon1;

	UPROPERTY(EditDefaultsOnly, Category = "WeaponsSetting")
	TSubclassOf<ASWeapon> Weapon2;

	ASWeapon* CurrentWeapon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArmComp;

	//是否需要视野变窄(开镜效果)
	bool bWantsToZoom;

	//窄视野
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	float ZoomedFOV;

	//默认视野
	float DefaultFOV;

	UPROPERTY(EditDefaultsOnly, Category = "Player", meta = (ClampMin = 0.1,ClampMax = 100))
	float ZoomInterpSpeed;

	void StartFire();
	void StopFire();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
