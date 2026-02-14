#include "SpecHelper.h"

#include <vector>
#include <Windows.h>

int SpecHelper::getPhysicalCoreCount()
{
	DWORD returnLength = 0;
	GetLogicalProcessorInformation(nullptr, &returnLength);

	std::vector<SYSTEM_LOGICAL_PROCESSOR_INFORMATION> elements;
	elements.resize(returnLength / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION));
	GetLogicalProcessorInformation(elements.data(), &returnLength);

	int processorCoreCount = 0;
	for (auto& element : elements)
	{
		if (element.Relationship == RelationProcessorCore)
		{
			processorCoreCount++;
		}
	}

	return processorCoreCount;
}