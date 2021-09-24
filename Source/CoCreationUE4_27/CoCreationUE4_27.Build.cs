// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System;
using System.IO;

public class CoCreationUE4_27 : ModuleRules
{
	public CoCreationUE4_27(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		// RapidLib
		AddRapidLibLibrary(Target);

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}

	void AddRapidLibLibrary(ReadOnlyTargetRules Target)
	{
		string module_path = ModuleDirectory;
		string rapidlib_path = Path.GetFullPath(Path.Combine(module_path, "../../Plugins/InteractML/Source", "3rdParty", "RapidLib"));
		string include_dir = Path.Combine(rapidlib_path, "src");
		string lib_dir = Path.Combine(rapidlib_path, "lib");

		//config
		bool is_lib_supported = false;
		if ((Target.Platform == UnrealTargetPlatform.Win64) || Target.Platform == UnrealTargetPlatform.HoloLens /*|| (Target.Platform==UnrealTargetPlatform.Win32)*/)
		{
			//platform variants
			string platform_string;
			if (Target.Platform == UnrealTargetPlatform.Win64)
			{
				platform_string = "x64";
			}
			else if (Target.Platform == UnrealTargetPlatform.HoloLens)
			{
				platform_string = "ARM64";
			}
			/*else if(Target.Platform==UnrealTargetPlatform.Win32)
			{
				platform_string = "Win32"; 	//NOTE: unlike x64, the Win32 platform is called "Win32"
			}*/
			else
			{
				throw new System.ApplicationException("Unsupported RapidLib build target platform " + Target.Platform);
			}

			//configuration
			string config_string; //shipping/test has none
			switch (Target.Configuration)
			{
				case UnrealTargetConfiguration.Debug:
				case UnrealTargetConfiguration.DebugGame:
				//full debug can't currently be supported (Unreal still links the release CRT)
				//instead, the debug build uses release CRL but is still unoptimised
				case UnrealTargetConfiguration.Development:
					config_string = "Debug";
					break;
				case UnrealTargetConfiguration.Shipping:
					config_string = "Release";
					break;
				default:
					throw new System.ApplicationException("Unsupported RapidLib build configuration " + Target.Configuration);
			}

			//narrow down location
			lib_dir = Path.Combine(lib_dir, platform_string, config_string);
			is_lib_supported = true;
		}

		if (is_lib_supported)
		{
			string lib_path = Path.Combine(lib_dir, "RapidLib.lib");

			PublicAdditionalLibraries.Add(lib_path);
			PublicIncludePaths.Add(include_dir);
		}
	}
}