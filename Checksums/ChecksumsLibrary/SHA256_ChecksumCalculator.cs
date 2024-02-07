using ChecksumsLibrary.ProgressIndicator;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary
{
    class SHA256_ChecksumCalculator : ChecksumCalculator
    {
        public override string calculate(Stream inputStream, string fileName)
        {
            using (SHA256 sha256 = SHA256.Create())
            {
                byte[] hashBytes = sha256.ComputeHash(inputStream);
                return BitConverter.ToString(hashBytes).Replace("-", "").ToLower();
            }
        }
    }
}
