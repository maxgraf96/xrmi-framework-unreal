// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

//#ifdef _WIN32
// #include <Winsock2.h> // before Windows.h, else Winsock 1 conflict
// #include <Ws2tcpip.h> // needed for ip_mreq definition for multicast
// #include <Windows.h>
//#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
//#endif

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGBUFSIZE 256

#include "UDPMulticastListener.generated.h"

UCLASS()
class COCREATIONUE4_27_API AUDPMulticastListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUDPMulticastListener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
