/*
	RuleEditWindow.h: Rule editor class (duh)
	Written by DarkWyrm <darkwyrm@gmail.com>, Copyright 2008
	Released under the MIT license.
*/
#ifndef RULE_EDIT_WINDNOW_H
#define RULE_EDIT_WINDNOW_H

#include <Box.h>
#include <LayoutBuilder.h>

#include "ActionView.h"
#include "FilerRule.h"
#include "TestView.h"


class RuleEditWindow : public BWindow
{
public:
				RuleEditWindow(BRect frame, FilerRule* rule, BHandler* caller);
	virtual		~RuleEditWindow();

	void		MessageReceived(BMessage* msg);

//	FilerRule*	Rule();

	void		UpdateEmptyCount(bool increment);

	void		AppendTest(BMessage* test);
	void		RemoveTest();

	void		AppendAction(BMessage* action);
	void		RemoveAction();
private:
	void		SendRuleMessage();

	AutoTextControl*	fDescriptionBox;

	BBox*			fTestGroup;
	BBox*			fActionGroup;

	BGroupLayout*	fTestGroupLayout;
	BGroupLayout*	fActionGroupLayout;

	BButton*		fOK;
	BButton*		fCancel;
	BButton*		fHelp;

	TestView*		fTestView;
	ActionView*		fActionView;

	int32			fEmptyCount;

	int64			fOriginalID;
	BHandler*		fCaller;

	BList			fTestList;
	BList			fActionList;
};

#endif	// RULE_EDIT_WINDNOW_H
