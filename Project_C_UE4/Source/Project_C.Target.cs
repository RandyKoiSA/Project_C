// Copyrighted by Devoted Koi

using UnrealBuildTool;
using System.Collections.Generic;

public class Project_CTarget : TargetRules
{
	public Project_CTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Project_C" } );
	}
}
