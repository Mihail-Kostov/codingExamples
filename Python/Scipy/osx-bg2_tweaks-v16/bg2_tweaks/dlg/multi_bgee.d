BEGIN ~MULTIG~

// this is what we say if we are kicked out and waiting around
IF ~Global("Waiting","LOCALS",1)
    !InParty(Myself)~ THEN BEGIN wait SAY #20672 // So do you want me back in the party?
  IF ~~ THEN REPLY @107002 DO ~SetGlobal("Waiting","LOCALS",0) // #74098, doesn't exist in SoA: "Please rejoin the party."
                              JoinParty()~ EXIT
  IF ~~ THEN REPLY #10887 EXIT // You will have to wait here. I have no room for you at the moment.
END

// this is what we say when we were just recently kicked out
IF ~Global("Waiting","LOCALS",0)
    !InParty(Myself)~ THEN BEGIN left SAY #19527 // Perhaps we shall meet again. Until next time, friends.
  IF ~~ THEN REPLY #10887 DO ~SetGlobal("Waiting","LOCALS",1)~ EXIT // wait here
  IF ~~ THEN REPLY @107002 DO ~JoinParty()~ EXIT    // #74098, doesn't exist in SoA: "Please rejoin the party."  
  IF ~!AreaCheck("AR0506")
      !AreaCheck("AR0507")
      !AreaCheck("AR0508")
      !AreaCheck("AR0509")
      !AreaCheck("AR0510")
      !AreaCheck("AR0511")
      !AreaCheck("AR0512")
      !AreaCheck("AR0513")
      !AreaCheck("AR0514")
      !AreaCheck("AR0515")
      !AreaCheck("AR0516")
      !AreaCheck("AR1008")
      !AreaCheck("AR1009")
      !AreaCheck("AR1500")
      !AreaCheck("AR1501")
      !AreaCheck("AR1502")
      !AreaCheck("AR1503")
      !AreaCheck("AR1504")
      !AreaCheck("AR1505")
      !AreaCheck("AR2000")
      !AreaCheck("AR2001")
      !AreaCheck("AR2002")
      !AreaCheck("AR2003")
      !AreaCheck("AR2004")
      !AreaCheck("AR2005")
      !AreaCheck("AR2006")
      !AreaCheck("AR2007")
      !AreaCheck("AR2008")
      !AreaCheck("AR2009")
      !AreaCheck("AR2010")
      !AreaCheck("AR2011")
      !AreaCheck("AR2012")
      !AreaCheck("AR2301")
      !AreaCheck("AR2615")
      !AreaCheck("AR2619")
      !AreaCheck("AR2643")
      !AreaCheck("AR5506")~ THEN REPLY @107001 DO ~SetGlobal("Waiting","LOCALS",1)
                                                   EscapeAreaMove("AR2301",311,715,0)~ EXIT // FAI
END

// how did we ever get here?
IF ~InParty(Myself)
    Gender(Myself,MALE)~ THEN BEGIN boy SAY #2106 //   Hello there.
  IF ~~ THEN EXIT
END

// how did we ever get here?
IF ~InParty(Myself)
    Gender(Myself,FEMALE)~ THEN BEGIN girl SAY #2106 //   Hello there.
  IF ~~ THEN EXIT
END