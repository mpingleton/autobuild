#include "../../include/autobuild.hpp"

#include <Xml.hpp>

using namespace Autobuild;

// TODO: As work is being done on the text-parser library, this code will eventually have to be re-written.
int AutobuildRepo::readAutobuildFile()
{
    XmlDocument autobuildFile;
    autobuildFile.readFile("autobuild.xml");
    if (autobuildFile.root.element == NULL)
    {
        return -1;
    }
    else if (autobuildFile.root.element->openingTag.text != "autobuild")
    {
        return -2;
    }

    for (int rootNodeChildIndex = 0; rootNodeChildIndex < autobuildFile.root.element->children.size(); rootNodeChildIndex++)
    {
        XmlElement* currentElement = autobuildFile.root.element->children[rootNodeChildIndex].element;
        if (currentElement->getElementName() == "target")
        {
            Target newTarget;
            newTarget.platform = currentElement->getAttribute("platform");
            newTarget.type = currentElement->getAttribute("type");
            newTarget.filenameOutput = currentElement->getAttribute("output");
            
            for (int i = 0; i < currentElement->children.size(); i++)
            {
                XmlElement* currentTargetElement = currentElement->children[i].element;
                if (currentTargetElement->getElementName() == "source")
                {
                    SourceFile newSourceFile;
                    newSourceFile.type = currentTargetElement->getAttribute("type");
                    newSourceFile.filename = currentTargetElement->getAttribute("file");

                    newTarget.sourceFiles.push_back(newSourceFile);
                }
                else if (currentTargetElement->getElementName() == "sourcegroup")
                {
                    std::string groupId = currentTargetElement->getAttribute("id");
                    if (!groupId.empty())
                    {
                        newTarget.sourceGroupIds.push_back(groupId);
                    }
                }
            }

            targets.push_back(newTarget);
        }
        else if (currentElement->getElementName() == "sourcegroup")
        {
            SourceGroup newSourceGroup;
            newSourceGroup.id = currentElement->getAttribute("id");
            for (int i = 0; i < currentElement->children.size(); i++)
            {
                XmlElement* currentSourceGroupElement = currentElement->children[i].element;
                if (currentSourceGroupElement->getElementName() == "source")
                {
                    CompileJob newCompileJob;
                    newCompileJob.source.type = currentSourceGroupElement->getAttribute("type");
                    newCompileJob.source.filename = currentSourceGroupElement->getAttribute("file");
                    newSourceGroup.compileJobs.push_back(newCompileJob);
                }
            }

            sourceGroups.push_back(newSourceGroup);
        }
    }

    return 0;
}
