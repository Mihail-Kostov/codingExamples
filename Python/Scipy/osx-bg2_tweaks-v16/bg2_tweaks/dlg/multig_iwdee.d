BEGIN ~MULTIG~

IF ~!InParty(Myself)
    Global("KickedOut","LOCALS",0)~ THEN BEGIN 0 SAY #40143 /* ~Do you want me to leave the party?~ */
  IF ~~ THEN REPLY #40144 /* ~No, stay with the group for now.~ */ DO ~SetGlobal("KickedOut","LOCALS",0)
                                                                       JoinParty()~ EXIT
  IF ~~ THEN REPLY #40145 /* ~Yes, please wait here for a while.~ */ DO ~SetGlobal("KickedOut","LOCALS",1)
                                                                         ChangeAIScript("",DEFAULT)~ EXIT
  IF ~Global("AR2000_visited","GLOBAL",0)
      Global("Chapter","GLOBAL",0)
      !AreaCheck("AR1006")
      OR(3) // make sure we're not in how/totl
        !GlobalGT("Hjollder_Quest","GLOBAL",2)
        Global("HOW_COMPLETED","GLOBAL",1)
        Global("Exp_Pause","GLOBAL",1)~ THEN REPLY @107004 DO ~SetGlobal("Waiting","LOCALS",1)
                                                               EscapeAreaMove("AR1006",442,492,13)~ EXIT // prologue, go to Winter's Cradle Tavern
  IF ~Global("AR2100_visited","GLOBAL",1)
      GlobalGT("Chapter","GLOBAL",0)
      Global("AR1100_visited","GLOBAL",0)
      !AreaCheck("AR2111")
      OR(3) // make sure we're not in how/totl
        !GlobalGT("Hjollder_Quest","GLOBAL",2)
        Global("HOW_COMPLETED","GLOBAL",1)
        Global("Exp_Pause","GLOBAL",1)~ THEN REPLY @107005 DO ~SetGlobal("Waiting","LOCALS",1)
                                                               EscapeAreaMove("AR2111",350,306,4)~ EXIT // anywhere but eh finale, go to Root Cellar Tavern
  IF ~GlobalGT("Hjollder_Quest","GLOBAL",2)
      !Global("HOW_COMPLETED","GLOBAL",1)
      !Global("Exp_Pause","GLOBAL",1)
      !AreaCheck("AR9101") // whistling gallows
      !AreaCheck("AR9300") // burial isle
      !AreaCheck("AR9301") // edions tower
      !AreaCheck("AR9400") // wylfdene's barrow
      !AreaCheck("AR9600") // sea of moving ice
      !AreaCheck("AR9601") // sea of moving ice - cave entrance
      !AreaCheck("AR9602") // sea of moving ice - field of bones
      !AreaCheck("AR9603") // sea of moving ice - icasaracht exterior
      !AreaCheck("AR9604") // sea of moving ice - icasaracht interior
      OR(2) // make sure we're not in totl
        Global("Master_Quest","GLOBAL",0)
        GlobalGT("Master_Quest","GLOBAL",6)~ THEN REPLY @107006 DO ~SetGlobal("Waiting","LOCALS",1)
                                                                    EscapeAreaMove("AR9101",885,585,8)~ EXIT // go to Whistling Gallows
END

IF ~!InParty(Myself)
    Global("KickedOut","LOCALS",1)~ THEN BEGIN 1 SAY #40146 /* ~Do you require my services once again?~ */
  IF ~~ THEN REPLY #40147 /* ~Yes, please rejoin the party.~ */ DO ~SetGlobal("KickedOut","LOCALS",0)
                                                                    JoinParty()~ EXIT
  IF ~~ THEN REPLY #40148 /* ~Not at this time.~ */ EXIT
END
