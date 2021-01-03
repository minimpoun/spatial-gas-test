// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

using UnrealBuildTool;

public class SpatialTest : ModuleRules
{
	public SpatialTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[] 
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"Sockets",
				"OnlineSubsystemUtils",
				"PhysXVehicles",
				"SpatialGDK",
				"GameplayAbilities"
			});
	}
}
