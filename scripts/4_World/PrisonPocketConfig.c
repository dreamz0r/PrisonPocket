class PrisonPocketConfig
{
	static const string CONFIG_DIR = "$profile:PrisonPocket";
	static const string CONFIG_PATH = "$profile:PrisonPocket/PrisonPocketConfig.json";

	int ConfigVersion = 1;
	ref array<string> AllowedItems = {"Zucchini"};
	float BleedChance = 0.25;

	protected static ref PrisonPocketConfig s_Config;

	static void Init()
	{
		if (!s_Config)
			Load();
	}

	static PrisonPocketConfig Get()
	{
		return s_Config;
	}

	protected static void Load()
	{
		if (!FileExist(CONFIG_DIR))
			MakeDirectory(CONFIG_DIR);

		string errorMessage;
		if (!FileExist(CONFIG_PATH))
		{
			s_Config = new PrisonPocketConfig;
			JsonFileLoader<PrisonPocketConfig>.SaveFile(CONFIG_PATH, s_Config, errorMessage);
			return;
		}

		PrisonPocketConfig loadedConfig;
		if (!JsonFileLoader<PrisonPocketConfig>.LoadFile(CONFIG_PATH, loadedConfig, errorMessage))
		{
			ErrorEx(errorMessage);
			s_Config = new PrisonPocketConfig;
			return;
		}

		s_Config = loadedConfig;
		s_Config.Validate();
		JsonFileLoader<PrisonPocketConfig>.SaveFile(CONFIG_PATH, s_Config, errorMessage);
	}

	void Validate()
	{
		if (!AllowedItems)
			AllowedItems = new array<string>;

		if (AllowedItems.Count() == 0)
			AllowedItems.Insert("Zucchini");

		BleedChance = Math.Clamp(BleedChance, 0.0, 1.0);
	}
};
