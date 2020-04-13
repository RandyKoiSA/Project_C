// Copyrighted by Devoted Koi

using UnrealBuildTool;
using System.Collections.Generic;

public class Project_CEditorTarget : TargetRules
{
	public Project_CEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Project_C" } );
	}
}
