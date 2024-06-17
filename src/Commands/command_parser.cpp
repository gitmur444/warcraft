#include "command_parser.h"
#include "create_map_command.h"
#include "spawn_unit_command.h"
#include "march_command.h"
#include "wait_command.h"

std::unique_ptr<Command> CommandParser::Parse(const std::string& command) {
    if (command.find(CreateMapCommand::COMMAND) == 0) {
        return CreateMapCommand::Parse(command);
    } else if (command.find(SpawnUnitCommand::COMMAND_WARRIOR) == 0 || command.find(SpawnUnitCommand::COMMAND_ARCHER) == 0) {
        return SpawnUnitCommand::Parse(command);
    } else if (command.find(MarchCommand::COMMAND) == 0) {
        return MarchCommand::Parse(command);
    } else if (command.find(WaitCommand::COMMAND) == 0) {
        return WaitCommand::Parse(command);
    }
    return nullptr;
}
