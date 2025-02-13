// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class planetWB_PP_AB : ModuleRules
{
	public planetWB_PP_AB(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
