class ItemPoppySeed: CA_Magazine {
	scope = 2;
	count = 1;
	displayName = "Poppy Seed";
	descriptionShort = "A Bag of Poppy Seed";
	weight = 0.1;
	model = "\z\addons\plantingassets\models\poppy_seed.p3d";
	picture = "\z\addons\plantingassets\pictures\equip_poppy_seed_CA.paa";
	type = 256;
	class ItemActions {
		class Crafting
		{
			text = "Craft Poppy Plant";
			script = ";['Crafting','CfgMagazines', _id] spawn player_craftItem;";
			neednearby[] = {""};
			requiretools[] = {"ItemKnife"};
			output[] = {{"ItemPoppyPlant",1},{"ItemWaterbottleUnfilled",1}};
			input[] = {{"ItemPoppySeed",1},{"ItemFertilizer",1},{"ItemWaterbottle",1}};
		};
	};
};

class ItemPoppyPlant: CA_Magazine {
	scope = 2;
	count = 1;
	displayName = "Poppy Plant";
	descriptionShort = "A Poppy Plant";
	weight = 0.1;
	model = "\z\addons\dayz_epoch\models\doc_child2.p3d";	// TODO: model + icon
	picture = "\z\addons\dayz_epoch\pictures\equip_child2_ca.paa";
	type = 256;
	class ItemActions {
		class Build {
			text = "Plant Poppy";
			script = "spawn player_build;";
			require[] = {"ItemEtool"};
			create = "poppy_stage1";			// TODO: model for Hemp Stage 1
		};
	};
};

class ItemPoppyTears: CA_Magazine {
	scope = 2;
	count = 1;
	displayName = "Poppy Tears";
	descriptionShort = "Poppy Tears";
	weight = 0.1;
	model = "z\addons\dayz_epoch\models\kilohemp.p3d";
	picture = "\z\addons\dayz_epoch\pictures\equip_kilohemp_CA.paa";
	type = 256;
	class ItemActions
	{
		class Crafting
		{
			text = "Craft Morphine Auto-Injector";
			script = ";['Crafting','CfgMagazines', _id] spawn player_craftItem;";
			neednearby[] = {"fire"};
			requiretools[] = {"ItemKnife"};
			output[] = {{"ItemMorphine",1}};
			input[] = {{"ItemPoppyTears",2}};
		};
	};
};
