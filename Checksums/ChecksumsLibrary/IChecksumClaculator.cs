using ChecksumsLibrary.ProgressIndicator;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary
{
    public interface IChecksumClaculator : ProcessedFileObservable
    {
        public String calculate(Stream inputStream);
    }
}
