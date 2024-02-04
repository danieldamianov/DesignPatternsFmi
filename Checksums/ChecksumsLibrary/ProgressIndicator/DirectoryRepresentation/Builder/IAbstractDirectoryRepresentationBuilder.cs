using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Builder
{
    public interface IAbstractDirectoryRepresentationBuilder
    {
        IAbstractFile Build();

        IAbstractDirectoryRepresentationBuilder
            AddAbstractFile(IAbstractFile abstractFile);
    }
}
