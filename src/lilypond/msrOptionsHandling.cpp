/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#include <climits>      /* INT_MIN, INT_MAX */
#include <iomanip>      // setw, set::precision, ...

#include "msrOptionsHandling.h"


using namespace std;

namespace MusicXML2 
{

// useful shortcut macros
#define idtr indenter::gIndenter
#define tab  indenter::gIndenter.getSpacer ()

//______________________________________________________________________________
msrOptionsElement::msrOptionsElement (
  string optionsElementShortName,
  string optionsElementLongName,
  string optionsElementDescription)
{
  fOptionsElementShortName   = optionsElementShortName;  
  fOptionsElementLongName    = optionsElementLongName;  
  fOptionsElementDescription = optionsElementDescription;  
}

msrOptionsElement::~msrOptionsElement()
{}

ostream& operator<< (ostream& os, const S_msrOptionsElement& elt)
{
  elt->print (os);
  return os;
}

void msrOptionsElement::print (ostream& os) const
{
  os << "??? msrOptionsElement ???" << endl;
}

//______________________________________________________________________________
msrOptionsItem::msrOptionsItem (
  string             optionsItemShortName,
  string             optionsItemLongName,
  string             optionsItemDescription,
  msrOptionsItemKind optionsItemKind)
  : msrOptionsElement (
      optionsItemShortName,
      optionsItemLongName,
      optionsItemDescription)
{
  fOptionsItemKind = optionsItemKind;
  
  fOptionsItemHasBeenSelected = false;
}
    
string optionsItemKindAsString (
  msrOptionsItemKind optionsItemKind)
{
  string result;
  
  switch (optionsItemKind) {
    case msrOptionsItem::kOptionsItemHasNoArgument:
      result = "OptionsItemHasNoArgument";
      break;
    case msrOptionsItem::kOptionsItemHasARequiredArgument:
      result = "OptionsItemHasARequiredArgument";
      break;
    case msrOptionsItem::kOptionsItemHasAnOptionsArgument:
      result = "OptionsItemHasAnOptionsArgument";
      break;
  } // switch

  return result;
}  

void msrOptionsItem::print (ostream& os) const
{
  const int fieldWidth = 19;
  
  os <<
    "OptionsItem ???:" <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementShortName" << " : " << fOptionsElementShortName <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementLongName" << " : " << fOptionsElementLongName <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementDescription" << " : " << fOptionsElementDescription <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsItemKind" << " : " <<
      optionsItemKindAsString (
        fOptionsItemKind) <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsItemHasBeenSelected" << " : " <<
    booleanAsString (
      fOptionsItemHasBeenSelected) <<
    endl;
}

ostream& operator<< (ostream& os, const S_msrOptionsItem& elt)
{
  os <<
    "OptionsItem ???:" <<
    endl;
  elt.print (os);
  return os;
}

//______________________________________________________________________________
msrOptionsBoolItem::msrOptionsBoolItem (
  string optionsItemShortName,
  string optionsItemLongName,
  string optionsItemDescription,
  bool&  optionsBoolItemVariable)
  : msrOptionsItem (
      optionsItemShortName,
      optionsItemLongName,
      optionsItemDescription,
      msrOptionsItem::kOptionsItemHasNoArgument),
    fOptionsBoolItemVariable (optionsBoolItemVariable)
{}

void msrOptionsBoolItem::print (ostream& os) const
{
  const int fieldWidth = 19;
  
  os <<
    "OptionsBoolItem:" <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementShortName" << " : " << fOptionsElementShortName <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementLongName" << " : " << fOptionsElementLongName <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementDescription" << " : " << fOptionsElementDescription <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsItemHasBeenSelected" << " : " <<
    booleanAsString (
      fOptionsItemHasBeenSelected) <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsBoolItemVariable" << " : " <<
    booleanAsString (
      fOptionsBoolItemVariable) <<
    endl;
}

ostream& operator<< (ostream& os, const S_msrOptionsBoolItem& elt)
{
  os <<
    "OptionsBoolItem:" <<
    endl;
  elt.print (os);
  return os;
}

//______________________________________________________________________________
msrOptionsIntItem::msrOptionsIntItem (
  string             optionsItemShortName,
  string             optionsItemLongName,
  string             optionsItemDescription,
  int&               optionsIntItemVariable,
  msrOptionsItemKind optionsItemKind)
  : msrOptionsItem (
      optionsItemShortName,
      optionsItemLongName,
      optionsItemDescription,
      optionsItemKind),
    fOptionsIntItemVariable (optionsIntItemVariable)
{}

void msrOptionsIntItemprint (ostream& os) const
{
  const int fieldWidth = 19;
  
  os <<
    "OptionsIntItem:" <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementShortName" << " : " << fOptionsElementShortName <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementLongName" << " : " << fOptionsElementLongName <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementDescription" << " : " << fOptionsElementDescription <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsItemHasBeenSelected" << " : " <<
    booleanAsString (
      fOptionsItemHasBeenSelected) <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsIntItemVariable" << " : " << fOptionsIntItemVariable <<
    endl;
}

ostream& operator<< (ostream& os, const S_msrOptionsIntItem& elt)
{
  os <<
    "OptionsIntItem:" <<
    endl;
  elt.print (os);
  return os;
}

//______________________________________________________________________________
msrOptionsFloatItem::msrOptionsFloatItem (
  string             optionsItemShortName,
  string             optionsItemLongName,
  string             optionsItemDescription,
  float&             optionsFloatItemVariable,
  msrOptionsItemKind optionsItemKind)
  : msrOptionsItem (
      optionsItemShortName,
      optionsItemLongName,
      optionsItemDescription,
      optionsItemKind),
    fOptionsFloatItemVariable (optionsFloatItemVariable)
{}

void msrOptionsFloatItem::print (ostream& os) const
{
  const int fieldWidth = 19;
  
  os <<
    "OptionsFloatItem:" <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementShortName" << " : " << fOptionsElementShortName <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementLongName" << " : " << fOptionsElementLongName <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementDescription" << " : " << fOptionsElementDescription <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsItemHasBeenSelected" << " : " <<
    booleanAsString (
      fOptionsItemHasBeenSelected) <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsFloatItemVariable" << " : " << fOptionsFloatItemVariable <<
    endl;
}

ostream& operator<< (ostream& os, const S_msrOptionsFloatItem& elt)
{
  os <<
    "OptionsFloatItem:" <<
    endl;
  elt.print (os);
  return os;
}

//______________________________________________________________________________
msrOptionsStringItem::msrOptionsStringItem (
  string             optionsItemShortName,
  string             optionsItemLongName,
  string             optionsItemDescription,
  string&            optionsStringItemVariable,
  msrOptionsItemKind optionsItemKind)
  : msrOptionsItem (
      optionsItemShortName,
      optionsItemLongName,
      optionsItemDescription,
      optionsItemKind),
    fOptionsStringItemVariable (optionsStringItemVariable)
{}

void msrOptionsStringItem::print (ostream& os) const
{
  const int fieldWidth = 19;
  
  os <<
    "OptionsStringItem:" <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementShortName" << " : " << fOptionsElementShortName <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementLongName" << " : " << fOptionsElementLongName <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementDescription" << " : " << fOptionsElementDescription <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsItemHasBeenSelected" << " : " <<
    booleanAsString (
      fOptionsItemHasBeenSelected) <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsStringItemVariable" << " : " << fOptionsStringItemVariable <<
    endl;
}

ostream& operator<< (ostream& os, const S_msrOptionsStringItem& elt)
{
  os <<
    "OptionsStringItem:" <<
    endl;
  elt.print (os);
  return os;
}

//______________________________________________________________________________
msrOptionsSubGroup::msrOptionsSubGroup (
  string optionsSubGroupShortName,
  string optionsSubGroupLongName,
  string optionsSubGroupDescription)
  : msrOptionsElement (
      optionsSubGroupShortName,
      optionsSubGroupLongName,
      optionsSubGroupDescription)
{}

void msrOptionsSubGroup::print (ostream& os) const
{
  const int fieldWidth = 19;
  
  os <<
    "OptionsSubGroup:" <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementShortName" << " : " << fOptionsElementShortName <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementLongName" << " : " << fOptionsElementLongName <<
    endl <<
    setw(fieldWidth) <<
    "fOptionsElementDescription" << " : " << fOptionsElementDescription <<
    endl;

  for (
    list<S_msrOptionsItem>::const_iterator
      i = fOptionsSubGroupItemsList.begin();
    i != fOptionsSubGroupItemsList.end();
    i++) {
    // print the element
    os << (*i);
  } // for
}

ostream& operator<< (ostream& os, const msrOptionsSubGroup& elt)
{
  os <<
    "OptionsSubGroup:" <<
    endl;
  elt.print (os);
  return os;
}

//______________________________________________________________________________

//______________________________________________________________________________

//______________________________________________________________________________



}