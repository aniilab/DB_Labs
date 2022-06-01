using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace MovieBase
{
    public partial class Production
    {
        public Production()
        {
            Movies = new HashSet<Movie>();
        }

        public int Id { get; set; }

        [Display(Name = "Назва кіностудії")]
        public string Name { get; set; } = null!;
        [Display(Name = "Країна")]
        public int CountryId { get; set; }


        [Display(Name = "Країна")]
        public virtual Country? Country { get; set; } = null!;
        [Display(Name = "Фільми")]
        public virtual ICollection<Movie>? Movies { get; set; }
    }
}
