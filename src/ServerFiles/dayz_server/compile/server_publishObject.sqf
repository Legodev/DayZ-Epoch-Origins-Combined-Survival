private ["_class","_uid","_charID","_object","_worldspace","_key","_allowed"];
//[dayz_characterID,_tent,[_dir,_location],"TentStorage"]
_charID =		_this select 0;
_object = 		_this select 1;
_worldspace = 	_this select 2;
_class = 		_this select 3;

_vector = [];
_ownerPUID = "";
if (_worldspaceLength >= 6) then {
_vector = 		_this select 4;
_ownerPUID = 		_this select 5;
};

_allowed = [_object, "Server"] call check_publishobject;
if (!_allowed) exitWith { deleteVehicle _object; };

//get UID
_uid = _worldspace call dayz_objectUID2;

_worldspace set [2, _vector];
_worldspace set [3, _ownerPUID];
_worldspace set [4, [1,0,[],[],[]]];

if (count _vector > 0) then {
	_object setVariable["vector",_vector,true];
};

if (_ownerPUID != "") then {
	_object setVariable ["ownerPUID", _ownerPUID, true];
};

if (isClass (configFile >> "CfgBuildingReceipt" >> _class >> "Stage1")) then {
	{
		_object animate _x;
	} forEach getArray (configFile >> "CfgBuildingReceipt" >> _class >> "Stage1" >> "animationStates");
	_object setVariable ["buildStage", 1,true];
	_worldspace set [4, [1,1,[],[],[]]];
};


//Send request
_key = format["CHILD:308:%1:%2:%3:%4:%5:%6:%7:%8:%9:",dayZ_instance, _class, 0 , _charID, _worldspace, [], [], 0,_uid];
//diag_log ("HIVE: WRITE: "+ str(_key));
_key call server_hiveWrite;

_object setVariable ["lastUpdate",time];
_object setVariable ["ObjectUID", _uid,true];
// _object setVariable ["CharacterID",_charID,true];

if (DZE_GodModeBase) then {
	_object addEventHandler ["HandleDamage", {false}];
} else {
	_object addMPEventHandler ["MPKilled",{_this call object_handleServerKilled;}];
};
// Test disabling simulation server side on buildables only.
_object enableSimulation false;

PVDZE_serverObjectMonitor set [count PVDZE_serverObjectMonitor,_object];

//diag_log ("PUBLISH: Created " + (_class) + " with ID " + _uid);