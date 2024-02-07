using System.Collections.Generic;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Builder
{
    public class AbstractDirectryRepresentationBuilder : IAbstractDirectoryRepresentationBuilder
    {
        protected Directory buildedObject;

        public AbstractDirectryRepresentationBuilder(string path)
        {
            this.buildedObject = new Directory(new List<IAbstractFile>(), path);
        }

        public IAbstractDirectoryRepresentationBuilder AddAbstractFile(IAbstractFile abstactFile)
        {
            this.buildedObject.AddResource(abstactFile);
            return this;
        }

        public IAbstractFile Build()
        {
            return this.buildedObject;
        }
    }
}
