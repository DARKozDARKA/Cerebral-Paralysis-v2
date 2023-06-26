// Fill out your copyright notice in the Description page of Project Settings.


#include "Infrastructure/MainGameInstance.h"

#include "Infrastructure/States/BootstrapState/UBootstrapState.h"



UMainGameInstance::UMainGameInstance()
{
	MainGameStateMachine = NewObject<UGameStateMachine>();
}

void UMainGameInstance::Init()
{
	Super::Init();
	StartGame();
}

void UMainGameInstance::OnWorldChanged(UWorld* OldWorld, UWorld* NewWorld)
{
	Super::OnWorldChanged(OldWorld, NewWorld);

	if (IsInitialized)
		return;

	IsInitialized = true;
	MainGameStateMachine->SetWorld(NewWorld);
}


void UMainGameInstance::StartGame()
{
	MainGameStateMachine->CreateStates();
	MainGameStateMachine->SetWorld(GetWorld());
	MainGameStateMachine->Enter<UBootstrapState>();
}

void UMainGameInstance::EnterLoadLevelState()
{
	MainGameStateMachine->Enter<ULoadLevelState>();
}