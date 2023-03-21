libpsutil::symbol<void(int arg, char *buffer, int bufferLength)> SV_Cmd_ArgvBuffer{ static_cast<int>(0x1DC37C) };

detour* ClientCommand_t;
void ClientCommand(int clientcommand)
{
	char SV_Cmd_Argv[1032];
	SV_Cmd_ArgvBuffer(3, SV_Cmd_Argv, 1024);
	if (strcmp(SV_Cmd_Argv, "endround") == 0)
	{
		if (clientcommand != CgArray_s->ClientNumber)
		{
			const char* message = va("^5%s ^3Tried End Game", CgArray_s->clientInfo[clientcommand].Name);
			iPrintIn(-1, message);
			return;
		}
	}
	ClientCommand_t->invoke<void>(clientcommand);
}

ClientCommand_t = new detour(0x182DEC, ClientCommand);