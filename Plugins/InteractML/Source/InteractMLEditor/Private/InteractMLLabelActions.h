//----
// InteractML - Interactive Machine Learning Plugin
// Copyright (c) 2021 Phoenix Perry and Rebecca Fiebrink
// Using the MIT License. https://github.com/Interactml
//----

#pragma once

#include "AssetTypeActions_Base.h"


////////////////////////////// LABEL /////////////////////////////


// expose our label asset type to various editor systems
//
class FInteractMLLabelActions : public FAssetTypeActions_Base
{
	uint32 RegisteredCategoryHandle;
public:
	
	FInteractMLLabelActions(uint32 InAssetCategory)
		: RegisteredCategoryHandle(InAssetCategory)
	{
		SetSupported(true);
	}
	
	// IAssetTypeActions Implementation
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
	virtual void OpenAssetEditor( const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>() ) override;
	// End IAssetTypeActions
	
};

