/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __pbxbuild_ScriptResolver_h
#define __pbxbuild_ScriptResolver_h

#include <pbxbuild/Base.h>
#include <pbxbuild/ToolInvocation.h>
#include <pbxbuild/TargetBuildRules.h>
#include <pbxbuild/Phase/PhaseEnvironment.h>

namespace pbxbuild {
namespace Tool {

class ToolContext;

class ScriptResolver {
private:
    pbxspec::PBX::Tool::shared_ptr _tool;

private:
    explicit ScriptResolver(pbxspec::PBX::Tool::shared_ptr const &tool);

public:
    void resolve(
        ToolContext *toolContext,
        pbxsetting::Environment const &environment,
        std::string const &workingDirectory,
        std::string const &shell,
        std::vector<std::string> const &arguments,
        std::unordered_map<std::string, std::string> const &environmentVariables,
        std::vector<ToolInvocation::AuxiliaryFile> const &auxiliaries,
        std::vector<std::string> const &inputFiles,
        std::vector<std::string> const &outputFiles,
        std::string const &logMessage
    ) const;
    void resolve(
        ToolContext *toolContext,
        pbxsetting::Environment const &environment,
        pbxproj::PBX::LegacyTarget::shared_ptr const &legacyTarget
    ) const;
    void resolve(
        ToolContext *toolContext,
        pbxsetting::Environment const &environment,
        pbxproj::PBX::ShellScriptBuildPhase::shared_ptr const &buildPhase
    ) const;
    void resolve(
        ToolContext *toolContext,
        pbxsetting::Environment const &environment,
        std::string const &inputFile,
        pbxbuild::TargetBuildRules::BuildRule::shared_ptr const &buildRule
    ) const;

public:
    pbxspec::PBX::Tool::shared_ptr const &tool() const
    { return _tool; }

public:
    static std::string ToolIdentifier()
    { return "com.apple.commands.shell-script"; }

public:
    static std::unique_ptr<ScriptResolver>
    Create(Phase::PhaseEnvironment const &phaseEnvironment);
};

}
}

#endif // !__pbxbuild_ScriptInvocationContext_h