// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SurvivorGame : ModuleRules
{
	public SurvivorGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay", 
			"NavigationSystem", 
			"AIModule", 
			"Niagara", 
			"EnhancedInput",
            "GameplayTasks",
            "SlateCore",
        });

        PublicIncludePaths.Add(ModuleDirectory);
    }
}
